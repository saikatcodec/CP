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
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;
        map<char, pair<int, int>> fp;

        for (int i = 0; i < n; i++) {
            if (str[i] >= 97) {
                fp[str[i]].first++;
            } else if (str[i] < 97) {
                fp[str[i] + 32].second++;
            }
        }

        int ans = 0;
        for (auto it : fp) {
            int minx = min(it.second.first, it.second.second);
            ans += minx;
            if (k > 0) {
                int maxx = max(it.second.first, it.second.second);
                int op = (maxx - minx) / 2;
                if (op <= k) {
                    k -= op;
                } else {
                    op = k;
                    k = 0;
                }
                ans += op;
            }
        }

        cout << ans << nl;
    }

    return 0;
}