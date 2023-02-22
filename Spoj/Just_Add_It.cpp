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
#define mod 10000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// clang-format on

ll binPow(ll n, ll k) {
    ll res = 1;

    while (k) {
        if (k & 1) {
            res = (res * n) % mod;
        }

        n = (n * n) % mod;
        k >>= 1;
    }

    return res % mod;
}

int main() {
    FIO;

    ll n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) {
            break;
        }

        ll ans;
        ans = (((2 * binPow(n - 1, k)) % mod) + ((2 * binPow(n - 1, n - 1)) % mod) + (binPow(n, k) % mod) + (binPow(n, n) % mod)) % mod;
        cout << ans << nl;
    }

    return 0;
}