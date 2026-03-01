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

int main() {
    int n, val;

    scanf("%d", &n);

    if (n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *last = NULL;

    // Create circular linked list
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

    // Make it circular
    last->next = head;

    // Traverse circular linked list
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}
