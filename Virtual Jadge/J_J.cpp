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

    int n, m;
    cin >> n >> m;

    map<int, vector<pair<int, int>>> add;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            add[c].push_back({i, j});
        }
    }

    ll ans = 0;

    for (auto v : add) {
        for (int i = 0; i < v.second.size(); i++) {
            for (int j = i + 1; j < v.second.size(); j++) {
                ans += (2 * (abs(v.second[i].first - v.second[j].first) +
                             abs(v.second[i].second - v.second[j].second)));
            }
        }
    }

    cout << ans << nl;

    return 0;
}