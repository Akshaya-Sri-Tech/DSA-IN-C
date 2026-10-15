#include <stdio.h>
#include "graph_matrix.h"

int main(void)
{
    Graph g1 = createGraph(5);

    addEdge(&g1, 0, 1);
    addEdge(&g1, 0, 3);
    addEdge(&g1, 0, 4);
    addEdge(&g1, 1, 2);


    printf("DFS: ");
    DFS(g1, 0);

    printf("\nBFS: ");
    BFS(g1, 0);

    printf("\n\n");

     Graph g = createGraph(9);

    addEdgeMST(&g, 0, 1, 4);
    addEdgeMST(&g, 0, 7, 8);
    addEdgeMST(&g, 1, 7, 11);
    addEdgeMST(&g, 1, 2, 8);
    addEdgeMST(&g, 2, 3, 7);
    addEdgeMST(&g, 2, 8, 2);
    addEdgeMST(&g, 2, 5, 4);
    addEdgeMST(&g, 3, 5, 14);
    addEdgeMST(&g, 3, 4, 9);
    addEdgeMST(&g, 4, 5, 10);
    addEdgeMST(&g, 5, 6, 2);
    addEdgeMST(&g, 6, 7, 1);
    addEdgeMST(&g, 7, 8, 7);
    addEdgeMST(&g, 8, 6, 6);

    prims(&g, 0);
    printf("Stored Prim's cost: %d\n", g.cost);

    kruskals(&g);
    printf("Stored Kruskal's cost: %d\n", g.cost);

    printf("BFS :  ");
    BFS(g,0);

    return 0;
}
