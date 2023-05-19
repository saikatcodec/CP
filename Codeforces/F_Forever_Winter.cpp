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

pair<int, int> degree(int n, map<int, list<int>> adj) {
    map<int, int> dt;

    for (int i = 1; i <= n; i++) {
        dt[adj[i].size()]++;
    }

    map<int, int>::reverse_iterator it = dt.rbegin();

    auto x = *(it);
    auto y = *(++it);

    if (x.second < y.second) {
        return {x.first, y.first};
    } else {
        return {y.first, x.first};
    }
}

int main() {
    FIO;

    testCase(t) {
        int n, m;
        cin >> n >> m;

        map<int, list<int>> adj;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        auto ans = degree(n, adj);
        cout << ans.first << " " << ans.second - 1 << nl;
    }

    return 0;
}