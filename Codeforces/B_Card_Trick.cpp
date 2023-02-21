#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long arr[n];
        for (long long i = 0; i < n; i++)
            cin >> arr[i];

        long long total = 0, m;
        cin >> m;

        for (long long i = 0; i < m; i++)
        {
            long long a;
            cin >> a;
            total += a;
        }

        total %= n;
        cout << arr[total] << endl;
    }

    return 0;
}