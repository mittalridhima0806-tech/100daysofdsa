#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // Initialize with large value (no edge)
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INT_MAX;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // undirected
    }

    int key[MAX];      // minimum weight to connect
    int visited[MAX];  // visited nodes

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1
    int totalCost = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1;

        // pick minimum key node
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = 1;
        totalCost += key[u];

        // update neighbors
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INT_MAX && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", totalCost);
    return 0;
}
