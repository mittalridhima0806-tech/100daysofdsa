#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node *front = NULL, *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if (choice == 2) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
