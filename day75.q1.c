#include <stdio.h>

int main() {
    int arr[1000], n;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxLen = 0;

    // Check all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                int len = j - i + 1;
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }

    printf("%d\n", maxLen);
    return 0;
}
