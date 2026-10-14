
#include <stdio.h>
#include <stdlib.h>
#include "graph_list.h"

void prims(GRAPH *g, int start)
{
    int visited[MAX] = {0};
    int edges = 0, cost = 0;

    if (start < 0 || start >= MAX || !g->present[start])
        return;

    visited[start] = 1;
    printf("LIST Prim's MST:\n");

    while (edges < g->n - 1) {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < MAX; i++) {
            if (!visited[i])
                continue;

            Node *p = g->head[i];
            while (p != NULL) {
                int j = p->vertex;

                if (!visited[j] && p->weight < min) {
                    min = p->weight;
                    u = i;
                    v = j;
                }

                p = p->next;
            }
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

typedef struct {
    int u, v, weight;
} Edge;

int findRoot(int parent[], int v)
{
    if (parent[v] != v)
        parent[v] = findRoot(parent, parent[v]);

    return parent[v];
}

void kruskals(GRAPH *g)
{
    Edge edgesList[MAX * (MAX - 1) / 2];
    int parent[MAX];
    int count = 0, selected = 0, cost = 0;

    for (int i = 0; i < MAX; i++)
        parent[i] = i;

    for (int i = 0; i < MAX; i++) {
        if (!g->present[i])
            continue;

        Node *p = g->head[i];
        while (p != NULL) {
            if (i < p->vertex) {
                edgesList[count++] =
                    (Edge){i, p->vertex, p->weight};
            }
            p = p->next;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (edgesList[j].weight < edgesList[i].weight) {
                Edge temp = edgesList[i];
                edgesList[i] = edgesList[j];
                edgesList[j] = temp;
            }
        }
    }

    printf("LIST Kruskal's MST:\n");

    for (int i = 0; i < count && selected < g->n - 1; i++) {
        int u = edgesList[i].u;
        int v = edgesList[i].v;

        int ru = findRoot(parent, u);
        int rv = findRoot(parent, v);

        if (ru != rv) {
            printf("%d - %d : %d\n",
                   u, v, edgesList[i].weight);

            parent[ru] = rv;
            cost += edgesList[i].weight;
            selected++;
        }
    }

    if (selected != g->n - 1) {
        printf("Graph is disconnected.\n");
        return;
    }

    printf("Total cost = %d\n", cost);
}
