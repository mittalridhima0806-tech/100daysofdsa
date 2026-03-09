#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX) return;

    pq[size++] = x;
}

// Find index of highest priority (smallest element)
int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex;
}

// Delete highest priority element
int deleteElement() {
    int index = findMinIndex();

    if (index == -1) return -1;

    int value = pq[index];

    for (int i = index; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;

    return value;
}

// Peek highest priority element
int peek() {
    int index = findMinIndex();

    if (index == -1) return -1;

    return pq[index];
}

int main() {

    int N;
    scanf("%d", &N);

    char operation[10];
    int x;

    for (int i = 0; i < N; i++) {

        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }

        else if (strcmp(operation, "delete") == 0) {
            printf("%d\n", deleteElement());
        }

        else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
