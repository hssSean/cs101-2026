#include <stdio.h>

int check_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
    int i = 2000;
    if (check_leap_year(i)) {
        printf("閏年\n");
    } else {
        printf("不是閏年\n");
    }
    return 0;
}