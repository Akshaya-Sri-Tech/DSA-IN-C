
#include <stdio.h>
#include <stdlib.h>
#include "graph_matrix.h"

Graph createGraph(int n)
{
    Graph g;
    g.n = n;
    g.cost=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g.matrix[i][j] = 0;

    return g;
}

void addEdge(Graph *g, int u, int v)
{
    if (u < 0 || u >= g->n ||
        v < 0 || v >= g->n || u == v)
        return;

    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}

void addEdgeMST(Graph *g, int u, int v, int w)
{
    if (u < 0 || u >= g->n ||
        v < 0 || v >= g->n || u == v || w <= 0)
        return;

    g->matrix[u][v] = w;
    g->matrix[v][u] = w;
}

void display(Graph g)
{
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++)
            printf("%3d ", g.matrix[i][j]);
        printf("\n");
    }
}

void DFS(Graph g, int start)
{
    if (start < 0 || start >= g.n)
        return;

    int visited[MAX] = {0};
    int stack[MAX], top = -1;

    stack[++top] = start;

    while (top != -1) {
        int v = stack[top--];

        if (visited[v])
            continue;

        visited[v] = 1;
        printf("%d ", v);

        for (int i = g.n - 1; i >= 0; i--)
            if (g.matrix[v][i] && !visited[i])
                stack[++top] = i;
    }
}

void BFS(Graph g, int start)
{
    if (start < 0 || start >= g.n)
        return;

    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < g.n; i++)
            if (g.matrix[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
    }
}
