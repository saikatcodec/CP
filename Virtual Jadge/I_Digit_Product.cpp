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

ll digitP(ll n) {
    ll ans = 1;
    while (n > 0) {
        ans = ((ans % mod) * ((n % 10) % mod)) % mod;
        n /= 10;
    }

    return ans % mod;
}

int main() {
    FIO;

    testCase(t) {
        ll l, r;
        cin >> l >> r;

        if (r - l >= 9) {
            cout << 0 << nl;
        } else {
            ll ans = 1;
            for (ll i = l; i <= r; i++) {
                ans = ((ans % mod) * (digitP(i) % mod)) % mod;
            }

            cout << ans << nl;
        }
    }

    return 0;
}