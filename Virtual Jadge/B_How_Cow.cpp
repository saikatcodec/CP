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

    int c = 0;
    testCase(t) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int q;
        cin >> q;
        cout << "Case " << ++c << ":" << nl;
        while (q--) {
            int x, y;
            cin >> x >> y;

            bool flag = false;

            if ((x >= x1 && x <= x2) && (y >= y1 && y <= y2)) {
                flag = true;
            }

            if (flag) {
                cout << "Yes" << nl;
            } else {
                cout << "No" << nl;
            }
        }
    }

    return 0;
}