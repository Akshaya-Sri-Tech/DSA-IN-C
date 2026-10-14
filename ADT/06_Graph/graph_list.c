
#include <stdio.h>
#include <stdlib.h>
#include "graph_list.h"

void createGraph(GRAPH *g)
{
    g->n = 0;

    for (int i = 0; i < MAX; i++) {
        g->present[i] = 0;
        g->head[i] = NULL;
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

    Node *p = g->head[u];
    while (p != NULL) {
        if (p->vertex == v) {
            p->weight = weight;

            Node *q = g->head[v];
            while (q != NULL) {
                if (q->vertex == u) {
                    q->weight = weight;
                    return;
                }
                q = q->next;
            }
            return;
        }
        p = p->next;
    }

    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));

    if (a == NULL || b == NULL) {
        free(a);
        free(b);
        return;
    }

    *a = (Node){v, weight, g->head[u]};
    *b = (Node){u, weight, g->head[v]};

    g->head[u] = a;
    g->head[v] = b;
}

void display(GRAPH *g)
{
    for (int i = 0; i < MAX; i++) {
        if (!g->present[i])
            continue;

        printf("%d: ", i);

        Node *p = g->head[i];
        while (p != NULL) {
            printf("(%d, w=%d) ", p->vertex, p->weight);
            p = p->next;
        }

        printf("\n");
    }
}
