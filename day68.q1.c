#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function for Kahn's Algorithm
void topoSort(int V, int E, int edges[][2]) {
    
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Step 1: Build graph + indegree
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        if (adj[u][v] == 0) { // avoid duplicate edge count
            adj[u][v] = 1;
            indegree[v]++;
        }
    }

    // Step 2: Queue
    int queue[MAX];
    int front = 0, rear = 0;

    // Push all nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    // Step 3: BFS
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Step 4: Check cycle
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}
