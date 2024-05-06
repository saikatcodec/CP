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
#define inf 1e9
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// clang-format on

unordered_map<int, vector<int>> adj;
unordered_map<int, int> dist;

void bfs(int src) {
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int frnt = q.front();
        q.pop();

        for (auto node : adj[frnt]) {
            if (dist[frnt] + 1 < dist[node]) {
                dist[node] = dist[frnt] + 1;
                q.push(node);
            }
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
        while (cin >> src >> ttl && (src + ttl != 0)) {
            dist.clear();

            for (auto u : adj) {
                dist[u.first] = inf;
            }

            bfs(src);

            int ans = 0;
            for (auto distance : dist) {
                if (distance.second > ttl) ans++;
            }

            cout << "Case " << ++c << ": " << ans
                 << " nodes not reachable from node " << src
                 << " with TTL = " << ttl << "." << nl;
        }
    }

    return 0;
}