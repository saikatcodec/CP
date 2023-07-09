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
        vector<string> v(3);
        for (int i = 0; i < 3; i++) {
            cin >> v[i];
        }

        string ans = "DRAW";
        for (int i = 0; i < 3; i++) {
            if (v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][0] != '.') {
                ans = v[i][0];
                break;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i] != '.') {
                ans = v[0][i];
                break;
            }
        }
        if (v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.') {
            ans = v[0][0];
        } else if (v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] != '.') {
            ans = v[0][2];
        }

        cout << ans << nl;
    }

    return 0;
}