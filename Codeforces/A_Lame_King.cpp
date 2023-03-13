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
        int a, b;
        cin >> a >> b;

        a = abs(a);
        b = abs(b);

        if (a == 0 || b == 0) {
            cout << 2 * max(a, b) - 1 << nl;
            continue;
        }

        int ans;
        if (a == b) {
            ans = 2 * min(a, b);
        } else {
            ans = 2 * min(a, b) + 2 * abs(a - b) - 1;
        }
        cout << ans << nl;
    }

    return 0;
}