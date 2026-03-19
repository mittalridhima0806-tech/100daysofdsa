#include <stdio.h>
#include <stdlib.h>

// Define structure of tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to calculate height of binary tree
int height(struct TreeNode* root) {
    // Base case: if tree is empty
    if (root == NULL)
        return 0;

    // Find height of left subtree
    int leftHeight = height(root->left);

    // Find height of right subtree
    int rightHeight = height(root->right);

    // Return max height + 1 (for current node)
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);

    // Queue for level order construction
    struct TreeNode* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct TreeNode* current = queue[front++];

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Read level order input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build tree
    struct TreeNode* root = buildTree(arr, n);

    // Calculate and print height
    printf("%d", height(root));

    return 0;
}
