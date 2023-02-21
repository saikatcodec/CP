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

ll bigPow(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) {
            ans = ((ans % mod) * a) % mod;
        }

        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}

int main() {
    FIO;

    testCase(t) {
        ll n;
        cin >> n;

        ll ans;
        if (n < 3) {
            ans = n;
        } else if (n % 3 == 0) {
            ans = bigPow(3, n / 3);
        } else if (n % 3 == 1) {
            ans = (bigPow(3, n / 3 - 1) * 4) % mod;
        } else if (n % 3 == 2) {
            ans = (bigPow(3, n / 3) * 2) % mod;
        }

        cout << ans << nl;
    }

    return 0;
}