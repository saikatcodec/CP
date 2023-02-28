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
#define mod 100000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// clang-format on

ll factorial[5000005];

ll fact(ll n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }

    return factorial[n] = ((n % mod) * (fact(n - 1) % mod)) % mod;
}

int main() {
    FIO;

    ll n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        ll ans = 1;
        for (ll i = 2; i <= n; i++) {
            ans = ((ans % mod) * (fact(i) % mod)) % mod;
        }

        cout << ans << nl;
    }

    return 0;
}