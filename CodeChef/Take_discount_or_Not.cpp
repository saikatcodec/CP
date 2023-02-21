#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x, y, total = 0, dis = 0;
        cin >> n >> x >> y;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            total += a;

            if (a <= y)
                dis += 0;
            else
                dis += (a - y);
        }

        if (dis + x < total)
            cout << "COUPON\n";
        else
            cout << "NO COUPON\n";
    }

    return 0;
}