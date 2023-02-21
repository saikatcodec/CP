#include <bits/stdc++.h>
using namespace std;

void appendArray(int n, int arr1[], int arr2[], int newArr[])
{
    for (int i = 0; i < n; i++)
        newArr[i] = arr1[i];
    for (int i = 0; i < n; i++)
        newArr[i + n] = arr2[i];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr1[n], arr2[n], newArr[n + n];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];

        appendArray(n, arr1, arr2, newArr);

        sort(newArr, newArr + (2 * n));
    }

    return 0;
}