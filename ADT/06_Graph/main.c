#include <stdio.h>
#include "graph_matrix.h"

int main(void)
{
    GRAPH g;
    createGraph(&g);

    for (int i = 0; i < 5; i++)
        insert(&g, i);

    addEdge(&g, 0, 1, 1);
    addEdge(&g, 0, 2, 2);
    addEdge(&g, 0, 3, 3);
    addEdge(&g, 2, 3, 4);
    addEdge(&g, 1, 2, 5);
    addEdge(&g, 4, 3, 6);
  

    printf("Weighted Graph:\n");
    display(&g);

    printf("\n");
    prims(&g, 1);

    printf("\n");
    kruskals(&g);

    return 0;
}