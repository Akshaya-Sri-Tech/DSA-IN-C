
#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#define MAX 20

typedef struct {
    int n;
    int cost;
    int matrix[MAX][MAX];
} Graph;

Graph createGraph(int n);
void addEdge(Graph *g, int u, int v);
void display(Graph g);
void addEdgeMST(Graph *g, int u, int v,int w);
void DFS(Graph g, int start);
void BFS(Graph g, int start);

void prims(Graph *g, int start);
void kruskals(Graph *g);
#endif
