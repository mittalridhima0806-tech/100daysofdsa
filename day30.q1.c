#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Print polynomial
void printPolynomial(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else if (temp->exp == 1)
            printf("%dx", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

int main() {
    int n, c, e;
    struct Node* head = NULL;

    scanf("%d", &n); // number of terms

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    printPolynomial(head);
    return 0;
}
