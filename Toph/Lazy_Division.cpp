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
// clang-format on
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    ll t, w;
    cin >> t;
    w = t;
    while (t--) {
        ll n, q;
        cin >> n >> q;

        ll arr[n + 1];
        for (ll i = 1; i < (n + 1); i++) {
            cin >> arr[i];
        }

        float pre[n + 2];
        for (ll i = 0; i < (n + 2); i++) {
            pre[i] = 1.0;
        }

        while (q--) {
            ll l, r, m;
            cin >> l >> r >> m;

            pre[l] *= m;
            pre[r + 1] /= m;
        }

        for (ll i = 1; i < (n + 1); i++) {
            pre[i] *= pre[i - 1];
            arr[i] = floor(arr[i] / pre[i]);
        }

        cout << "Case " << (w - t) << ":";
        for (ll i = 1; i < (n + 1); i++) {
            cout << " " << arr[i];
        }
        cout << nl;
    }

    return 0;
}