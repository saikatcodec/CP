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

vector<vector<pair<int, int>>> adj;
vector<bool> vis;
int cost = 0;

void dfs(int src, int parent) {
    vis[src] = true;

    for (auto [v, w] : adj[src]) {
        if (!vis[v]) {
            cost += w;
            dfs(v, src);
        } else if (v != parent && v == 1) {
            cost += w;
        }
    }
}

int main() {
    FIO;

    int n;
    cin >> n;

    adj.resize(n + 2);
    vis.resize(n + 2);

    int tot_cost = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, 0});
        adj[b].push_back({a, c});
        tot_cost += c;
    }

    dfs(1, -1);
    cout << min(cost, tot_cost - cost) << nl;

    return 0;
}