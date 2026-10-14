#include <stdio.h>
#include "graph_matrix.h"

void createGraph(GRAPH *g)
{
    g->n = 0;

    for (int i = 0; i < MAX; i++) {
        g->present[i] = 0;
        for (int j = 0; j < MAX; j++)
            g->adj[i][j] = 0;
    }
}

void insert(GRAPH *g, int v)
{
    if (v < 0 || v >= MAX || g->present[v])
        return;

    g->present[v] = 1;
    g->n++;
}

void addEdge(GRAPH *g, int u, int v, int weight)
{
    if (u < 0 || u >= MAX || v < 0 || v >= MAX)
        return;

    if (!g->present[u] || !g->present[v] ||
        u == v || weight <= 0)
        return;

    g->adj[u][v] = weight;
    g->adj[v][u] = weight;
}

void display(GRAPH *g)
{
    for (int i = 0; i < MAX; i++)
        if (g->present[i]) {
            printf("%d: ", i);

            for (int j = 0; j < MAX; j++)
                if (g->adj[i][j])
                    printf("(%d, w=%d) ", j, g->adj[i][j]);

            printf("\n");
        }
}