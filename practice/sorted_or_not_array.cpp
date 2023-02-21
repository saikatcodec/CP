#include <bits/stdc++.h>
using namespace std;

bool isSorted(int n, int arr[])
{
    if (n == 1)
        return true;

    bool flag = isSorted(n - 1, arr + 1);
    if ((arr[0] <= arr[1]) && flag)
        return true;
    else
        return false;
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

        if (isSorted(n, arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}