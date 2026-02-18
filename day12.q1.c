#include <stdio.h>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    int flag = 1;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");
    return 0;
}
