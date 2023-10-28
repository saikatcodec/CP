#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    while (n > 0) {
        int tmp = n % 10;
        n /= 10; // n = n / 10;
        printf("%d\n", tmp);
    }

    return 0;
}