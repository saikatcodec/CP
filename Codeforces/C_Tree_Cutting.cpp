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
vector<bool> vist;

int lowDegree(int n) {
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            return i;
        }
    }
}

int dfs(int src) {
    vist[src] = true;

    int cnt = 0;
    for (int n : adj[src]) {
        if (!vist[n]) cnt = max(cnt, dfs(n));
    }

    return cnt + 1;
}

int main() {
    FIO;

    testCase(t) {
        adj.clear();
        vist.clear();

        int n, k;
        cin >> n >> k;

        adj.resize(n + 2);
        vist.resize(n + 2);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root = lowDegree(n);
        int depth = dfs(root);
        cout << depth / (k + 1) << nl;
    }

    return 0;
}