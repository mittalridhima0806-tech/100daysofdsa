#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Stack
int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

// DFS for topo sort
void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
        temp = temp->next;
    }

    push(node); // push after visiting all neighbors
}

// Topological Sort function
void topoSort(int V, int E, int edges[][2]) {
    struct Node* adj[V];

    // Initialize
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Build graph (directed)
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // DFS on all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
        }
    }

    // Print topological order
    while (top != -1) {
        printf("%d ", pop());
    }
}
