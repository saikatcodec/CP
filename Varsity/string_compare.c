#include <stdio.h>

int stringCmp(char str1[], char str2[])
{
    int i = 0;
    for (; str1[i] != '\0' || str2[i] != '\0'; i++)
    {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
    }

    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else
        return -2;
}

int main()
{
    int n, m;
    printf("Enter two string length : ");
    scanf("%d %d", &n, &m);

    char str1[n], str2[m];
    scanf("%s", str1);
    scanf("%s", str2);

    int val = stringCmp(str1, str2);

    switch (val)
    {
    case 0:
        printf("Equal\n");
        break;

    case 1:
        printf("True\n");
        break;
    case -1:
        printf("False\n");
        break;

    default:
        printf("Problems occurred\n");
        break;
    }

    return 0;
}