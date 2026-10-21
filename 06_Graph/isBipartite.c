#include "../ADT/06_Graph/graph_matrix.h"
#include <stdio.h>

typedef enum
{
    FALSE,
    TRUE
} BOOL;

BOOL isBipartite(int n, Graph g, int color[], int cur)
{
    for (int i = 0; i < n; i++)
    {
        if (g.matrix[cur][i] == 1)
        {
            if (color[i] == -1)
            {
                color[i] = 1 - color[cur];
                if (!isBipartite(n, g, color, i))
                    return FALSE;
            }
            else if (color[i] == color[cur]) return FALSE;
        }
    }
    return TRUE;
}

int main()
{
    int n = 5;
    Graph g1 = createGraph(n);

    addEdge(&g1, 0, 1);
    addEdge(&g1, 0, 2);
    addEdge(&g1, 0, 4);
    addEdge(&g1, 1, 2);

    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = -1;
    BOOL result = TRUE;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (isBipartite(n, g1, color, i) == FALSE)
            {
                result = FALSE;
                break;
            }
        }
    }

    if (result == TRUE)
        printf("TRUE... It is Bipartite");
    else
        printf("FALSE... No It is not Bipartite");

    return 0;
}
