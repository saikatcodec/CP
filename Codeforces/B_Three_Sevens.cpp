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
        int m;
        cin >> m;

        vector<vector<int>> day(m);

        for (int d = 0; d < m; d++) {
            int n;
            cin >> n;

            vector<int> per(n);
            for (int i = 0; i < n; i++) {
                cin >> per[i];
            }

            day[d] = per;
        }

        unordered_map<int, int> numDay;
        for (int d = 0; d < m; d++) {
            for (int i = 0; i < day[d].size(); i++) {
                numDay[day[d][i]] = d + 1;
            }
        }

        map<int, int> mp;
        for (auto [num, day] : numDay) {
            mp[day] = num;
        }

        if (mp.size() >= m) {
            int d = 1;
            for (auto p : mp) {
                if (d > m) {
                    break;
                }
                cout << p.second << " ";
                d++;
            }
            cout << nl;
        } else {
            cout << -1 << nl;
        }
    }

    return 0;
}