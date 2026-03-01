#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Rotate function
struct Node* rotateRight(struct Node* head, int k) {
    
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make it circular
    temp->next = head;

    // Handle k > length
    k = k % length;
    int steps = length - k;

    // Find new last node
    struct Node* newLast = head;
    for (int i = 1; i < steps; i++) {
        newLast = newLast->next;
    }

    // Set new head
    struct Node* newHead = newLast->next;
    newLast->next = NULL;

    return newHead;
}

int main() {
    int n, k, val;
    struct Node* head = NULL;
    struct Node* last = NULL;

    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    // Print rotated list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
