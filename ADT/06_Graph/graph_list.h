
#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#define MAX 10
#define INF 999999

typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct {
    int n;
    int present[MAX];
    Node *head[MAX];
} GRAPH;

void createGraph(GRAPH *g);
void insert(GRAPH *g, int v);
void addEdge(GRAPH *g, int u, int v, int weight);
void display(GRAPH *g);

void prims(GRAPH *g, int start);
void kruskals(GRAPH *g);

#endif
