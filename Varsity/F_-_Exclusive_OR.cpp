#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

ll doXOR(ll n)
{
    ll y = n % 4;
    if (y == 0)
        return n;
    else if (y == 1)
        return 1;
    else if (y == 2)
        return n + 1;
    else if (y == 3)
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    ll ans = (doXOR(a - 1) ^ doXOR(b));
    cout << ans << nl;

    return 0;
}