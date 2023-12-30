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
        string grid[3];
        pair<int, int> pos;
        for (int i = 0; i < 3; i++) {
            cin >> grid[i];
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == '?') {
                    pos = {i, j};
                }
            }
        }

        bool flag[3] = {false};
        for (int i = 0; i < 3; i++) {
            flag[grid[i][pos.second] - 'A'] = true;
        }
        for (int i = 0; i < 3; i++) {
            flag[grid[pos.first][i] - 'A'] = true;
        }

        if (flag[0] == false) {
            cout << 'A' << nl;
        } else if (flag[1] == false) {
            cout << 'B' << nl;
        } else if (flag[2] == false) {
            cout << 'C' << nl;
        }
    }

    return 0;
}