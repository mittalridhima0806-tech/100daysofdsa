#include <stdio.h>
#include <stdlib.h>

// Interval structure
typedef struct {
    int start;
    int end;
} Interval;

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    // Step 2: Merge
    Interval result[n];
    int index = 0;

    result[index] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            // Merge overlapping
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // No overlap → new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Step 3: Print result
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}
