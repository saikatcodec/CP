#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        ll ans = (k * (k + 1)) / 2;
        if (ans <= n)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }

    return 0;
}