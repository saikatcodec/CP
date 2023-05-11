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

int dfs(int i, int j, vector<vector<int>> &adj, vector<vector<bool>> &visited) {
    int n = adj.size();
    int m = adj[0].size();

    visited[i][j] = true;
    int cnt = adj[i][j];

    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

    for (int h = 0; h < 4; h++) {
        int x = i + dx[h];
        int y = j + dy[h];

        if (x >= 0 && y >= 0 && x < n && y < m && adj[x][y] > 0 && !visited[x][y]) {
            cnt += dfs(x, y, adj, visited);
        }
    }

    return cnt;
}

int main() {
    FIO;

    testCase(t) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> adj[i][j];
            }
        }

        int ans = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && adj[i][j] > 0) {
                    cnt = dfs(i, j, adj, visited);
                }

                ans = max(ans, cnt);
            }
        }

        cout << ans << nl;
    }

    return 0;
}