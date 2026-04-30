#include <stdlib.h>

// Structure for car
typedef struct {
    int pos;
    int speed;
} Car;

// Comparator (descending by position)
int compare(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->pos - c1->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    // Step 1: Create car array
    Car cars[positionSize];
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = 0.0;

    // Step 3: Traverse
    for (int i = 0; i < positionSize; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    return fleets;
}
