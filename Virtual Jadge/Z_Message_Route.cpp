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

vector<vector<int>> adj;
vector<int> parent, dist;
vector<bool> vis;

void bfs(int src) {
    vis[src] = true;
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int fnt = q.front();
        q.pop();

        for (int node : adj[fnt]) {
            if (!vis[node]) {
                q.push(node);
                dist[node] = dist[fnt] + 1;
                parent[node] = fnt;
                vis[node] = true;
            }
        }
    }
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    adj.resize(n + 2);
    dist.resize(n + 2, INT_MAX);
    parent.resize(n + 2, -1);
    vis.resize(n + 2, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    vector<int> ans;
    int tmp = n;
    while (tmp != -1) {
        ans.push_back(tmp);
        tmp = parent[tmp];
    }

    reverse(ans.begin(), ans.end());

    if (*ans.begin() == 1 && *ans.rbegin() == n) {
        cout << ans.size() << nl;
        for (auto ele : ans) {
            cout << ele << " ";
        }
        cout << nl;
    } else {
        cout << "IMPOSSIBLE" << nl;
    }

    return 0;
}