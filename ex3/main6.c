#include <stdio.h>

#define FREE_MINUTES 30
#define UNIT_MINUTES 30
#define UNIT_PRICE 30
#define DAILY_MAX 240

int calc_parking_fee(int minutes) {
    if (minutes <= FREE_MINUTES) {
        return 0;
    }
    int units = (minutes + UNIT_MINUTES - 1) / UNIT_MINUTES;
    int fee = units * UNIT_PRICE;
    return (fee > DAILY_MAX) ? DAILY_MAX : fee;
}

int main() {
    int i = 20;
    int fee = calc_parking_fee(i);
    if (fee == 0) {
        printf("§K¶O\n");
    } else {
        printf("%d¤¸\n", fee);
    }
    return 0;
}