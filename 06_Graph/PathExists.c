#include "../ADT/06_Graph/graph_matrix.h"
#include<stdio.h>

typedef enum
{
    FALSE,
    TRUE
} BOOL;

BOOL pathExists(int n,int curr,int des,Graph g,int visited[]){
    if(curr==des) return TRUE;
    visited[curr]=1;
    for(int i=0;i<n;i++){
        if(g.matrix[curr][i]==1 && visited[i]==0){
            if(pathExists(n,i,des,g,visited))
                return TRUE;
        }
    }
    return FALSE;
}

int main(){
    int n=5;
    Graph g1 = createGraph(n);

    addEdge(&g1, 0, 1);
    addEdge(&g1, 0, 2);
    addEdge(&g1, 0, 4);
    addEdge(&g1, 1, 2);

    int visited[n];
    for(int i=0;i<n;i++) visited[i]=0;
 
    if(pathExists(n,0,3,g1,visited))
        printf("TRUE... Path exists between them");
    else
        printf("FALSE... No path between them");
}