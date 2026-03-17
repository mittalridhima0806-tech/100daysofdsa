#include <stdio.h>
#include <stdlib.h>

// Stack implementation using array
struct Stack {
    int top;
    int capacity;
    int* arr;
};

// Queue implementation using array
struct Queue {
    int front, rear, size;
    int capacity;
    int* arr;
};

// Stack functions
struct Stack* createStack(int cap) {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->capacity = cap;
    s->top = -1;
    s->arr = (int*)malloc(cap * sizeof(int));
    return s;
}

void push(struct Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

// Queue functions
struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = cap;
    q->front = 0;
    q->size = 0;
    q->rear = cap - 1;
    q->arr = (int*)malloc(cap * sizeof(int));
    return q;
}

void enqueue(struct Queue* q, int x) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = x;
    q->size++;
}

int dequeue(struct Queue* q) {
    int x = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return x;
}

// Reverse queue using stack
void reverseQueue(struct Queue* q) {
    struct Stack* s = createStack(q->capacity);

    // Step 1: Push all queue elements into stack
    while (q->size > 0) {
        push(s, dequeue(q));
    }

    // Step 2: Push back into queue
    while (s->top != -1) {
        enqueue(q, pop(s));
    }
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue(N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }

    reverseQueue(q);

    // Print reversed queue
    while (q->size > 0) {
        printf("%d ", dequeue(q));
    }

    return 0;
}
