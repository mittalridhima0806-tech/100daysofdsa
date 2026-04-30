#include <stdio.h>
#include <stdlib.h>

// Structure for interval
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

// Min Heap functions
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

void insertHeap(int heap[], int* size, int val) {
    int i = (*size)++;
    heap[i] = val;

    // Heapify up
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void removeMin(int heap[], int* size) {
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
}

int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;

    // Step 1: Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), compare);

    int* heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    // Add first meeting
    insertHeap(heap, &size, intervals[0].end);

    // Process rest
    for (int i = 1; i < n; i++) {
        // If earliest meeting ends before current starts
        if (heap[0] <= intervals[i].start) {
            removeMin(heap, &size);
        }

        insertHeap(heap, &size, intervals[i].end);
    }

    int result = size;
    free(heap);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval intervals[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    printf("%d", minMeetingRooms(intervals, n));

    return 0;
}
