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
        int n, m;
        cin >> n >> m;

        string grid[n];
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        bool bTop, bLeft, bRight, bBtm;
        bTop = bLeft = bRight = bBtm = false;

        bool wTop, wLeft, wRight, wBtm;
        wTop = wLeft = wRight = wBtm = false;

        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 'B') {
                bTop = true;
            }
            if (grid[0][i] == 'W') {
                wTop = true;
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[n - 1][i] == 'B') {
                bBtm = true;
            }
            if (grid[n - 1][i] == 'W') {
                wBtm = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'B') {
                bLeft = true;
            }
            if (grid[i][0] == 'W') {
                wLeft = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid[i][m - 1] == 'B') {
                bRight = true;
            }
            if (grid[i][m - 1] == 'W') {
                wRight = true;
            }
        }

        bool b = bTop && bLeft && bRight && bBtm;
        bool w = wTop && wLeft && wRight && wBtm;

        if (b || w) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}