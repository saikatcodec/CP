#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define int long long
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

unordered_map<int, vector<int>> adj;
unordered_map<int, bool> vis;

void dfs(int src, int ttl) {
    vis[src] = true;
    if (ttl == 0) {
        return;
    }

    for (auto node : adj[src]) {
        if (!vis[node]) {
            dfs(node, ttl - 1);
        }
    }
}

int32_t main() {
    FIO;

    int nc, c = 0;
    while (cin >> nc && nc > 0) {
        adj.clear();

        for (int i = 0; i < nc; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int src, ttl;
        while (cin >> src >> ttl && (src > 0 && ttl > 0)) {
            vis.clear();
            dfs(src, ttl);
            int ans = adj.size() - vis.size();
            cout << "Case " << ++c << ": " << ans
                 << " nodes not reachable from node " << src
                 << " with TTL = " << ttl << "." << nl;
        }
    }

    return 0;
}