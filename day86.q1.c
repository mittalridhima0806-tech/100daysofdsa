#include <stdio.h>

int integerSqrt(int n) {
    if (n == 0 || n == 1)
        return n;

    int left = 0, right = n, ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // To avoid overflow, use mid <= n / mid instead of mid*mid <= n
        if (mid <= n / mid) {
            ans = mid;          // possible answer
            left = mid + 1;     // try for a larger value
        } else {
            right = mid - 1;    // go left
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSqrt(n));

    return 0;
}
