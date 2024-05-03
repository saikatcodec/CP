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
vector<int> col;

bool dfs(int src, int parent, int colr) {
    col[src] = colr;

    for (auto node : adj[src]) {
        if (col[node] == 0) {
            bool flag = dfs(node, src, 3 - colr);
            if (flag) return true;
        } else if ((node != parent) && (col[node] == colr)) {
            return true;
        }
    }

    return false;
}

int main() {
    FIO;

    int n;
    while (cin >> n && n > 0) {
        adj.clear();
        col.clear();
        adj.resize(n);
        col.resize(n, 0);

        int m;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool flag = dfs(0, -1, 1);
        if (flag) {
            cout << "NOT BICOLORABLE." << nl;
        } else {
            cout << "BICOLORABLE." << nl;
        }
    }

    return 0;
}