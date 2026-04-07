#include <stdio.h>

int isMinHeap(int arr[], int n) {
    // Check all internal nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Left child index
        int left = 2 * i + 1;
        // Right child index
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] > arr[left]) {
            return 0;
        }

        // Check right child
        if (right < n && arr[i] > arr[right]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input level-order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
