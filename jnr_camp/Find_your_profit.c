#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (a % 5 == 0) {
        a += 10;
    } else if (a % 6 == 0) {
        a *= -2;
    }
    if (b % 5 == 0) {
        b += 10;
    } else if (b % 6 == 0) {
        b *= -2;
    }
    if (c % 5 == 0) {
        c += 10;
    } else if (c % 6 == 0) {
        c *= -2;
    }

    if (a > b) {
        if (a > c) {
            printf("%d ", a);
        } else {
            printf("%d ", c);
        }
    } else {
        if (b > c) {
            printf("%d ", b);
        } else {
            printf("%d ", c);
        }
    }

    return 0;
}