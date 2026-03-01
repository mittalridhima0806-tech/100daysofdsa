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

// Append node at end
struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Find length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Find intersection by value
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    // Move pointer of longer list
    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) p1 = p1->next;
    } else {
        int diff = len2 - len1;
        while (diff--) p2 = p2->next;
    }

    // Traverse together
    while (p1 && p2) {
        if (p1->data == p2->data)
            return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }

    return -1; // No intersection
}

int main() {
    int n, m, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // First list input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head1 = append(head1, val);
    }

    // Second list input
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        head2 = append(head2, val);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}
