#include <stdio.h>

#define PI 3.14159265358979

double calc_circumference(int diameter) {
    double c = diameter * PI;
    return (long)(c * 100000) / 100000.0;
}

int main() {
    int i = 1;
    printf("%.5f\n", calc_circumference(i));
    return 0;
}