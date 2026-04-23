#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0}; // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        freq[idx]++;

        // if this is second occurrence → return immediately
        if (freq[idx] == 2) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("-1\n"); // no repeated character
    return 0;
}
