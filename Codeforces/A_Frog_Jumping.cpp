#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, k;
        cin >> a >> b >> k;

        int mid = k / 2;
        if (k & 1)
            mid++;

        cout << (a * mid) - (b * (k - mid)) << endl;
    }

    return 0;
}