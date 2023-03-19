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

int main() {
    FIO;

    testCase(t) {
        ll n, q;
        cin >> n >> q;

        ll arr[n], total = 0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }

        ll pref[n + 1] = {0};
        for (ll i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + arr[i - 1];
        }

        while (q--) {
            ll l, r, k;
            cin >> l >> r >> k;

            ll remS = total - (pref[r] - pref[l - 1]);
            ll ans = remS + (r - l + 1) * k;

            if (ans & 1) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }

    return 0;
}