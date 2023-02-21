#include <bits/stdc++.h>
using namespace std;

bool isSorted(int n, long long arr[])
{
    if (n == 1)
        return true;
    bool flag = isSorted(n - 1, arr + 1);

    if (arr[0] <= arr[1] && flag)
        return true;
    else
        return false;
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long arr[n];
        long long negative = 0;
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < 0)
            {
                negative++;
                arr[i] *= -1;
            }
        }

        for (long long i = 0; i < negative; i++)
        {
            arr[i] *= -1;
        }

        if (isSorted(n, arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}