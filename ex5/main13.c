#include <stdio.h>
int multi(int a, int b){
    if (b == 1) {
        printf("%d*%d = %d\n", a, b, a*b);
        return 0;
    } else {
        multi( a, b - 1);
        printf("%d*%d = %d\n", a, b, a*b);
    }
}

int main() {
    multi(1,9);
    return 0;
}