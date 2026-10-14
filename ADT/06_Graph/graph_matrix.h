#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 999999

typedef struct
{
    int n;
    int adj[MAX][MAX];
    int present[MAX];
} GRAPH;

void createGraph(GRAPH *g);
void insert(GRAPH *g, int v);
void addEdge(GRAPH *g, int u, int v,int weight);
void display(GRAPH *g);
void DFS(GRAPH *g, int start);
void BFS(GRAPH *g, int start);

void prims(GRAPH *g, int start);
void kruskals(GRAPH *g);

#endif