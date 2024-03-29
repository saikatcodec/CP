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
        ll n, m;
        cin >> n >> m;

        ll l = 1, r = inf;
        ll ans;
        while (l <= r) {
            ll mid = (l + r) / 2;

            ll rem = mid - floor(mid * 1.0 / n);
            if (rem >= m) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << nl;
    }

    return 0;
}