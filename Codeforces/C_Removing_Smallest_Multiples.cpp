#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        string bs;
        cin >> bs;

        ll cost[n + 1];
        for (ll i = n; i >= 1; i--)
        {
            for (ll j = i; j <= n; j += i)
            {
                if (bs[j - 1] == '1')
                    break;
                cost[j] = i;
            }
        }

        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (bs[i - 1] == '0')
                ans += cost[i];
        }

        cout << ans << nl;
    }

    return 0;
}