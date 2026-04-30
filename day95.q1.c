#include <stdio.h>
#include <stdlib.h>

// Structure for linked list (for each bucket)
struct Node {
    float value;
    struct Node* next;
};

// Insert in sorted order (for individual bucket)
void insertSorted(struct Node** head, float val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = val;
    newNode->next = NULL;

    // Insert at beginning
    if (*head == NULL || (*head)->value >= val) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Insert in middle/end
    struct Node* current = *head;
    while (current->next != NULL && current->next->value < val) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    struct Node* buckets[n];

    for (int i = 0; i < n; i++)
        buckets[i] = NULL;

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        insertSorted(&buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->value;
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
