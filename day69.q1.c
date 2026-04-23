#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// -------- Min Heap --------
struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

// Insert into heap
void push(struct MinHeap* h, int v, int d) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = d;

    // Fix heap
    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract min
struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}

// -------- Dijkstra --------
void dijkstra(int V, int adj[MAX][MAX], int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    // Initialize
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap h;
    h.size = 0;

    push(&h, src, 0);

    while (h.size > 0) {
        struct HeapNode node = pop(&h);
        int u = node.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !visited[v]) {
                int newDist = dist[u] + adj[u][v];

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(&h, v, newDist);
                }
            }
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}
