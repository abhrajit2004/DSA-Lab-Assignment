#include<stdio.h>

// n: number of vertices ; m: number of edges
int n,m;

void createAdjMatrix(int adj[][n+1], int arr[][2]){
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            adj[i][j] = 0;
        }
        
    }

    for (int i = 0; i < m; i++)
    {
        int x = arr[i][0];
        int y = arr[i][1];

        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    
}

void printAdjMatrix(int adj[][n+1]){
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}

int main(){
    n = 5;
    int arr[][2] = {{1, 2},{2, 3},{4, 5},{1, 5}};

    int adj[n+1][n+1];

    m = sizeof(arr)/sizeof(arr[0]);

    createAdjMatrix(adj, arr);
    printAdjMatrix(adj);
    return 0;
}