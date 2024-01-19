#include<stdio.h>
#include<stdlib.h>

int node;
int visited[7] = {0,0,0,0,0,0,0};
int adj[7][7] = {
        {0,1,1,1,0,0,0},        
        {1,0,1,0,0,0,0},        
        {1,1,0,1,1,0,0},        
        {1,0,1,0,1,0,0},        
        {0,0,1,1,0,1,1},        
        {0,0,0,0,1,0,0},        
        {0,0,0,0,1,0,0}        
};

void DFS(int i){
    printf("%d ",i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(adj[i][j] == 1 && !visited[j]){
            DFS(j);
        }
    }
    
}

int main(){

    // DFS Implementation
    
    DFS(1);

    return 0;
}