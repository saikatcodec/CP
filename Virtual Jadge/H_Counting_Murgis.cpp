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

ll fact(ll n) {
    ll f = 1;
    for (int i = 2; i <= n; i++) {
        f = f * i;
    }

    return f;
}

int main() {
    FIO;

    testCase(t) {
        int n, k;
        cin >> n >> k;

        if (n <= k) {
            cout << 0 << nl;
        } else {
            n--;
            ll nf = fact(n);
            ll rf = fact(k);
            ll nrf = fact(n - k);

            ll ans = nf / (rf * nrf);
            cout << ans << nl;
        }
    }

    return 0;
}