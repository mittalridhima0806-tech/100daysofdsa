#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

// Check if deque is empty
int empty() {
    if(front == -1)
        return 1;
    return 0;
}

// Return size
int size() {
    if(front == -1)
        return 0;
    return rear - front + 1;
}

// Insert at front
void push_front(int value) {
    if(front == 0) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    } else {
        front--;
    }

    deque[front] = value;
}

// Insert at rear
void push_back(int value) {
    if(rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

// Delete from front
void pop_front() {
    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if(front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Delete from rear
void pop_back() {
    if(empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if(front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Get front element
void get_front() {
    if(empty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

// Get rear element
void get_back() {
    if(empty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

// Display deque
void display() {
    if(empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for(int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    get_front();
    get_back();

    pop_front();
    pop_back();

    display();

    printf("Size: %d\n", size());

    if(empty())
        printf("Deque is empty\n");
    else
        printf("Deque is not empty\n");

    return 0;
}
