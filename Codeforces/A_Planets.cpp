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
        ll n, c, ans = 0;
        cin >> n >> c;

        unordered_map<ll, vector<ll>> mp;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            mp[a].push_back(i + 1);
        }

        for (auto eleP : mp)
        {
            ll size = eleP.second.size();
            ans += min(size, c);
        }

        cout << ans << nl;
    }

    return 0;
}