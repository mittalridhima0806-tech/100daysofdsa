#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int node, int parent, bool visited[], int adj[MAX][MAX], int V) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {  // if there is an edge
            if (!visited[i]) {
                if (dfs(i, node, visited, adj, V))
                    return true;
            }
            else if (i != parent) {
                return true;  // cycle found
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, V)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
