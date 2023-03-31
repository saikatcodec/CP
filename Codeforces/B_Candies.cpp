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

        vector<int> path;
        int cnt = 40;
        int y = n;
        bool flag = true;
        while (cnt--) {
            if (y == 1) {
                break;
            }
            int a = y - 1;
            int b = y + 1;

            if (b % 2 == 0 && ((b / 2) & 1)) {
                path.push_back(1);
                y = b / 2;
            } else if (a % 2 == 0 && ((a / 2) & 1)) {
                path.push_back(2);
                y = a / 2;
            } else {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << path.size() << nl;
            reverse(path.begin(), path.end());
            for (auto ele : path) {
                cout << ele << " ";
            }
            cout << nl;
        } else {
            cout << -1 << nl;
        }
    }

    return 0;
}