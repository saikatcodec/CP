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

vector<bool> visited;
vector<int> parent;
vector<vector<int>> adj(100005);
int st, en;

bool dfs_hel(int s, int p) {
    visited[s] = true;
    parent[s] = p;

    for (auto node : adj[s]) {
        if (node == p) continue;
        if (visited[node]) {
            en = node;
            st = s;
            return true;
        }
        if (!visited[node]) {
            if (dfs_hel(node, s)) {
                return true;
            }
        }
    }

    return false;
}

bool dfs(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs_hel(i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    visited.resize(n + 1, false);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool flag = dfs(n);
    if (!flag) {
        cout << "IMPOSSIBLE" << nl;
    } else {
        vector<int> ans;
        int ss = st;

        ans.push_back(ss);
        while (ss != en) {
            ss = parent[ss];
            ans.push_back(ss);
        }
        ans.push_back(st);

        cout << ans.size() << nl;
        for (auto p : ans) {
            cout << p << " ";
        }
        cout << nl;
    }

    return 0;
}