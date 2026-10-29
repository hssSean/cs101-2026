#include <stdio.h>
int move = 0;
void tower(int n,char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        move++;
        return;
    }
    tower(n - 1, from, aux, to);
    move++;
    printf("Move disk %d from %c to %c\n", n, from, to);
    tower(n - 1, aux, to, from);
}

int main() {
    int n = 3;
    tower(n, 'A', 'C', 'B');
    printf("%d次",move);
    return 0;
}