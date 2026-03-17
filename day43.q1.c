#include <stdio.h>
#include <stdlib.h>

// -------- Tree Node --------
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// -------- Create Node --------
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// -------- Queue for Tree Construction --------
struct Queue {
    struct Node** arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = cap;
    q->front = 0;
    q->size = 0;
    q->rear = cap - 1;
    q->arr = (struct Node**)malloc(cap * sizeof(struct Node*));
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    struct Node* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// -------- Build Tree from Level Order --------
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);

    enqueue(q, root);
    int i = 1;

    while (i < n) {
        struct Node* current = dequeue(q);

        // Left child
        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    return root;
}

// -------- Inorder Traversal --------
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// -------- Main --------
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    inorder(root);

    return 0;
}
