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
        ll n, ans = 0;
        cin >> n;

        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            mp[a]++;
        }

        for (auto ele : mp)
        {
            if (ele.second > 1)
            {
                ans = ans + (((ele.second) * (ele.second - 1)) / 2);
            }
        }

        cout << ans << endl;
    }

    return 0;
}