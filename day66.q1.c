#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100005

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// DFS with recursion stack
bool dfs(int node, struct Node* adj[], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = false; // backtrack
    return false;
}

// Main function
char* isCyclic(int V, int E, int edges[][2]) {
    struct Node* adj[V];

    // Initialize adjacency list
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Build directed graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    bool visited[V];
    bool recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
                return "YES";
        }
    }

    return "NO";
}
