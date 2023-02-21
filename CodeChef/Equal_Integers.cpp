#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll x, y;
        cin >> x >> y;

        if (x == y)
            cout << "0"
                 << "\n";
        else if (x > y)
        {
            ll dif = x - y;
            ll ans = (dif % 2 == 0) ? (dif / 2) : ceil(dif / 2.0) + 1;
            cout << ans << "\n";
        }
        else
        {
            ll dif = y - x;
            cout << dif << "\n";
        }
    }

    return 0;
}