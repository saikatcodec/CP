#include <iostream>
#include <cstring>
using namespace std;

bool hasEven(int n, int len, int arr[])
{
    int flag[len];
    memset(flag, -1, sizeof(flag));

    for (int i = 0, j = 0; i < n; i += 2)
    {
        flag[j++] = arr[i] & 1;
    }

    for (int i = 0; i < len - 1; i++)
    {
        if (flag[i] != flag[i + 1])
        {
            return false;
        }
    }

    return true;
}

bool hasOdd(int n, int len, int arr[])
{
    int flag[len];
    memset(flag, -1, sizeof(flag));

    for (int i = 1, j = 0; i < n; i += 2)
    {
        flag[j++] = arr[i] & 1;
    }

    for (int i = 0; i < len - 1; i++)
    {
        if (flag[i] != flag[i + 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int len = n & 1 ? (n / 2) + 1 : n / 2;
        bool even = hasEven(n, len, arr);
        bool odd = hasOdd(n, n - len, arr);

        if (even && odd)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}