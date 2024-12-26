#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void addEdge(int adj[MAX][MAX], int u, int v){
    adj[u][v]=1;

    adj[v][u]=1;
}

void bfs(int adj[MAX][MAX], int V, int s){
    //Queue creation
    
    int q[MAX], front = 0, rear = 0;

    bool visited[MAX] = {false};

    visited[s] = true;

    q[rear++] = s;
    
    while (front < rear) {
        int curr = q[front++];
        printf("%d\t", curr);
        
        for(int i = 0; i<V;i++){
            if(adj[curr][i]==1 && !visited[i]){
                visited[i]=true;
                q[rear++]=i;
            }
        }
    }
    printf("\n");
}

void dfs(int adj[MAX][MAX], int V, int s, bool visited[MAX]){
    visited[s]=true;

    printf("%d\t", s);

    for(int i=0; i<V;i++){
        if(adj[s][i] == 1 && !visited[i])
            dfs(adj, V, i, visited);
    }
}


void main(){
    int V = 11;
    int adj[MAX][MAX]={0};
    bool visited[MAX] = {false};

    addEdge(adj, 3, 7);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 10);
    addEdge(adj, 10, 5);
    addEdge(adj, 5, 4);
    addEdge(adj, 4, 6);
    addEdge(adj, 6, 7);
    

    printf("BFS starting from 3: \n");
    bfs(adj, V, 3);
    printf("DFS starting from 3: \n");
    dfs(adj, V, 3, visited);

}

