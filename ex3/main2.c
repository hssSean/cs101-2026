#include <stdio.h>

int check_power_of_two(int n) {
    return n > 1 && (n & (n - 1)) == 0;
}

int main() {
    int i = 10;
    if (check_power_of_two(i)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}