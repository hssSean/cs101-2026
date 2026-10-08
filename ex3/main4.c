#include <stdio.h>

int check_odd(int n) {
    return n & 0x1;
}

int main() {
    int i = 10;
    if (check_odd(i)) {
        printf("odd\n");
    } else {
        printf("even\n");
    }
    return 0;
}