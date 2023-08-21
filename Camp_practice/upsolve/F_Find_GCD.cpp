#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// clang-format on
vector<ll> fact(1e5 + 1);

ll bigPow(ll n, ll b, ll m) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans = ((ans % m) * (n % m)) % m;
        }

        b >>= 1;
        n = ((n % m) * (n % m)) % m;
    }

    return ans % m;
}

int main() {
    FIO;
    ll x = 1;
    fact[0] = 1;
    for (ll i = 1; i <= 1e5; i++) {
        x = ((i % (mod - 1)) * (fact[i - 1] % (mod - 1))) % (mod - 1);
        fact[i] = x;
    }

    testCase(t) {
        ll n, a, b;
        cin >> a >> b >> n;
        a = min(a, b);

        ll fac = fact[a];
        ll ans = bigPow(n, fac, mod) % (mod);
        cout << ans << nl;
    }

    return 0;
}