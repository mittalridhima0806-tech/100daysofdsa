#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, size;

// Enqueue operation
void enqueue(int value) {
    if ((rear + 1) % size == front) {
        return; // queue full
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
}

// Dequeue operation
void dequeue() {
    if (front == -1) {
        return; // queue empty
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

// Display queue
void display() {
    if (front == -1) return;

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % size;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    size = n + 5; // extra space
    queue = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int temp = queue[front];
        dequeue();
        enqueue(temp);   // circular shift
    }

    display();

    free(queue);

    return 0;
}
