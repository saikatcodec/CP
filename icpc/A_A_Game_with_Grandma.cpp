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
        int n;
        cin >> n;

        char grid[3][n];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> prev, crnt;
        crnt = {-1, -1};
        vector<bool> flag;
        int cnt = 0, mid = 0;
        for (int j = 0; j < n; j++) {
            int line = 0;
            for (int i = 0; i < 3; i++) {
                char ch = grid[i][j];
                if (grid[i][j] == 'X') {
                    prev = crnt;
                    crnt = {i, j};
                    line++;
                    bool cont;
                    if (flag.size() > 1 && flag.back()) {
                        cont = true;
                    } else {
                        cont = false;
                    }

                    if ((prev.first != -1) && (abs(crnt.first - prev.first) == 2) && abs(crnt.second - prev.second) == 1) {
                        cnt++;
                    } else if (cont && i == 1) {
                        cnt++;
                    } else if (i == 1) {
                        mid++;
                    } else {
                        cnt++;
                    }
                }
            }

            if (line > 0) {
                flag.push_back(true);
            } else {
                flag.push_back(false);
            }
        }

        cout << cnt << " " << mid << nl;
    }

    return 0;
}