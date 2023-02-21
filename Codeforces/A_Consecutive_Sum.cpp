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
        ll n, k, sum = 0;
        cin >> n >> k;

        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (ll j = 0; j < k; j++)
        {
            ll maxV = INT_MIN;
            for (ll i = j; i < n; i += k)
            {
                maxV = max(maxV, arr[i]);
            }

            sum += maxV;
        }

        cout << sum << endl;
    }

    return 0;
}