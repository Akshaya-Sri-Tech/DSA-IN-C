#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void DFS_mat(int n, int g[n][n], int v, int visited[MAX], int k)
{
    if (k == -1) return;

    printf("%2d", v);
    visited[v] = 1;

    for (int i = 0; i < MAX; i++)
    {
        if (g[v][i] == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            DFS_mat(n, g, i, visited, k - 1);
        }
    }
}

int main()
{
    int G1[][MAX] = {
        {0,1,1,0,0},
        {1,0,0,0,1},
        {1,0,0,1,0},
        {0,0,1,0,0},
        {0,1,0,0,0}
    };

    int G2[][MAX] = {
        {0,1,0,0,0},
        {1,0,1,1,0},
        {0,1,0,0,1},
        {0,1,0,0,0},
        {0,0,1,0,0}
    };

    int k = 2;
    int start = 1;

    printf("\nG1 :\n");
    int v1[MAX] = {0};
    DFS_mat(MAX, G1, start, v1, k);

    printf("\nG2 :\n");
    int v2[MAX] = {0};
    DFS_mat(MAX, G2, start, v2, k);

    return 0;
}