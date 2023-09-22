#include <stdio.h>

int main() {
    int x, y;
    scanf("%d%d", &x, &y);

    if (y == 0) {
        printf("Divisible Impossible\n");
    } else {
        printf("%.1f\n", x * 1.0 / y);
    }

    return 0;
}