#include <stdio.h>

int calc_number(int x, int y, int z) {
    if (x < 0) {
        return x * 100 - y * 10 - z;
    }
    return x * 100 + y * 10 + z;
}

int main() {
    int x = 9;
    int y = 9;
    int z = 1;
    printf("%d\n", calc_number(x, y, z));
    return 0;
}