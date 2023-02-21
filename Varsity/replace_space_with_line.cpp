#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[100], dummy;
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    scanf("%c", &dummy);
    printf("Enter string: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &a[i]);
    }

    printf("Print after modifying: \n");
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == ' ')
            cout << endl;
        else
            cout << a[i];

        i++;
    }
    cout << endl;

    return 0;
}