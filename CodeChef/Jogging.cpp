#include <stdio.h>

int main()
{
    int a, b, n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        int c = b;
        if (a > 1)
        {
            c = (b * a) % 1000000007;
        }
        else
            c = b;
        printf("%d\n", c);
    }
    return 0;
}