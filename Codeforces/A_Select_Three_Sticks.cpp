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

        ll arr[n];
        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        vector<ll> v;
        ll ans = INT_MAX;
        for (ll i = 0; i < n - 2; i++)
        {
            ll temp = 0;
            temp += abs(arr[i] - arr[i + 1]);
            temp += abs(arr[i + 1] - arr[i + 2]);
            ans = min(ans, temp);
        }

        cout << ans << nl;
    }

    return 0;
}