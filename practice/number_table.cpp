#include <stdio.h>
int main()
{
    int namta[10][10];
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            namta[i][j] = i * (j + 1);
        }
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", namta[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int count = 0;
    printf("Even Number:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((namta[i][j] % 2) == 0)
            {
                count++;

                printf("%d\t", namta[i][j]);
            }
        }
    }
    printf("\n");
    printf("Odd Number:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((namta[i][j] % 2) != 0)
            {
                printf("%d\t", namta[i][j]);
            }
        }
    }

    return 0;
}