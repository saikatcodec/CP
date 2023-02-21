#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[100];
    for (int i = 0; i < 5; i++)
    {
        scanf("%c", &a[i]);
    }

    printf("Character array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");

    return 0;
}