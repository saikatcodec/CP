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

ll bigPow(ll n, ll k) {
    ll ans = 1;

    while (k > 0) {
        if (k & 1) {
            ans = ((ans % mod) * (n % mod) % mod);
        }

        k >>= 1;
        n = ((n % mod) * (n % mod)) % mod;
    }

    return ans % mod;
}

int main() {
    FIO;

    ll n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) {
            break;
        }

        ll a = (2 * bigPow(n - 1, k)) % mod;
        ll b = (2 * bigPow(n - 1, n - 1)) % mod;
        ll c = bigPow(n, k);
        ll d = bigPow(n, n);

        cout << (a + b + c + d) % mod << nl;
    }

    return 0;
}