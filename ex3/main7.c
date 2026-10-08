#include <stdio.h>

#define BASE_DISTANCE 1500
#define BASE_FARE 70
#define UNIT_DISTANCE 100
#define UNIT_FARE 10

int calc_taxi_fare(int distance) {
    if (distance <= BASE_DISTANCE) {
        return BASE_FARE;
    }
    int extra = distance - BASE_DISTANCE;
    int units = (extra + UNIT_DISTANCE - 1) / UNIT_DISTANCE;
    return BASE_FARE + units * UNIT_FARE;
}

int main() {
    int i = 1000;
    printf("%d¤¸\n", calc_taxi_fare(i));
    return 0;
}