#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n, q;
    cin >> n >> q;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    ll sum = 0;
    vector<ll> sumV;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        sum += v[i];
        sumV.push_back(sum);
    }

    while (q--)
    {
        ll x, y;
        cin >> x >> y;

        if (x == y)
        {
            cout << sumV[x - 1] << endl;
            continue;
        }

        cout << sumV[x - 1] - sumV[x - y - 1] << endl;
    }

    return 0;
}