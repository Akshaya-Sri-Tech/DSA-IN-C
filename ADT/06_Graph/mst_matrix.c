#include <stdio.h>
#include "graph_matrix.h"

#define MAX 20
#define INF 999999

void prims(Graph *g, int start)
{
    int visited[MAX] = {0};
    int min, u, v;
    g->cost = 0;
    if (start < 0 || start >= g->n)
        return;
    visited[start] = 1;
    printf("\nPrim's MST:\n");
    for (int e = 0; e < g->n - 1; e++) {
        min = INF;
        u = v = -1;
        for (int i = 0; i < g->n; i++)
            if (visited[i])
                for (int j = 0; j < g->n; j++)
                    if (!visited[j] && g->matrix[i][j] &&
                        g->matrix[i][j] < min) {
                        min = g->matrix[i][j];
                        u = i;
                        v = j;
                    }
        if (v == -1) {
            printf("Graph is disconnected.\n");
            g->cost = 0;
            return;
        }
        visited[v] = 1;
        g->cost += min;
        printf("%d - %d : %d\n", u, v, min);
    }
    printf("Minimum Cost = %d\n", g->cost);
}

int find(int parent[], int x)
{
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void kruskals(Graph *g)
{
    int parent[MAX];
    int edgeCount = 0, selected = 0;
    int u, v, min, a, b;
    int used[MAX][MAX] = {0};
    g->cost = 0;
    for (int i = 0; i < g->n; i++)
        parent[i] = i;
    printf("\nKruskal's MST:\n");
    while (selected < g->n - 1) {
        min = INF;
        u = v = -1;
        for (int i = 0; i < g->n; i++)
            for (int j = i + 1; j < g->n; j++)
                if (g->matrix[i][j] && !used[i][j] &&
                    g->matrix[i][j] < min) {
                    min = g->matrix[i][j];
                    u = i;
                    v = j;
                }
        if (u == -1) {
            printf("Graph is disconnected.\n");
            g->cost = 0;
            return;
        }
        used[u][v] = used[v][u] = 1;
        a = find(parent, u);
        b = find(parent, v);
        if (a != b) {
            parent[a] = b;
            g->cost += min;
            selected++;
            printf("%d - %d : %d\n", u, v, min);
        }
    }
    printf("Minimum Cost = %d\n", g->cost);
}
