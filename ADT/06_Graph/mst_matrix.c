#include <stdio.h>
#include "graph_matrix.h"

void prims(GRAPH *g, int start)
{
    int visited[MAX] = {0};
    int edges = 0, cost = 0;

    if (start < 0 || start >= MAX || !g->present[start])
        return;

    visited[start] = 1;
    printf("MATRIX Prim's MST:\n");

    while (edges < g->n - 1) {
        int min = INF, u = -1, v = -1;
        for (int i = 0; i < MAX; i++)
            if (visited[i])
                for (int j = 0; j < MAX; j++)
                    if (g->present[j] && !visited[j] &&
                        g->adj[i][j] > 0 &&
                        g->adj[i][j] < min) {
                        min = g->adj[i][j];
                        u = i;
                        v = j;
                    }
        if (v == -1) {
            printf("Graph is disconnected.\n");
            return;
        }

        printf("%d - %d : %d\n", u, v, min);
        visited[v] = 1;
        cost += min;
        edges++;
    }

    printf("Total cost = %d\n", cost);
}

int find(int parent[], int v)
{
    while (parent[v] != v)
        v = parent[v];

    return v;
}

void kruskals(GRAPH *g)
{
    int parent[MAX];
    int edges = 0, cost = 0;

    for (int i = 0; i < MAX; i++)
        parent[i] = i;

    printf("MATRIX Kruskal's MST:\n");

    while (edges < g->n - 1) {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < MAX; i++)
            if (g->present[i])
                for (int j = i + 1; j < MAX; j++)
                    if (g->present[j] &&
                        g->adj[i][j] > 0 &&
                        g->adj[i][j] < min &&
                        find(parent, i) != find(parent, j)) {
                        min = g->adj[i][j];
                        u = i;
                        v = j;
                    }

        if (u == -1) {
            printf("Graph is disconnected.\n");
            return;
        }

        printf("%d - %d : %d\n", u, v, min);
        parent[find(parent, u)] = find(parent, v);
        cost += min;
        edges++;
    }

    printf("Total cost = %d\n", cost);
}