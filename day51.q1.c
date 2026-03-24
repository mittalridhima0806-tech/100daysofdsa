#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (n1 < root->data && n2 < root->data) {
        return findLCA(root->left, n1, n2);
    }

    if (n1 > root->data && n2 > root->data) {
        return findLCA(root->right, n1, n2);
    }

    return root; // This is the LCA
}

int main() {
    struct Node* root = NULL;
    int n, val, n1, n2;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL) {
        printf("%d", lca->data);
    }

    return 0;
}
