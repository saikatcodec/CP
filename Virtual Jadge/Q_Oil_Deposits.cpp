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

map<int, vector<int>> adj;
map<int, bool> vis;

void dfs(int src) {
    vis[src] = true;

    for (auto node : adj[src]) {
        if (!vis[node]) {
            dfs(node);
        }
    }
}

int count_components() {
    int cnt = 0;

    for (auto p : adj) {
        if (!vis[p.first]) {
            cnt++;
            dfs(p.first);
        }
    }

    return cnt;
}

int main() {
    FIO;

    int m, n;
    while (cin >> m >> n && m != 0) {
        adj.clear();
        vis.clear();

        string str[m];
        for (int i = 0; i < m; i++) {
            cin >> str[i];
        }

        int dx[] = {1, 1, 0, -1, 0, 1, -1, -1};
        int dy[] = {0, 1, -1, 0, 1, -1, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int node = n * i + j + 1;

                if (str[i][j] == '@') {
                    adj[node].push_back(node);

                    for (int k = 0; k < 8; k++) {
                        int ii = i + dx[k];
                        int jj = j + dy[k];

                        if ((ii >= 0 && ii < m) && (jj >= 0 && jj < n)) {
                            if (str[ii][jj] == '@') {
                                int adjacent = n * ii + jj + 1;
                                adj[node].push_back(adjacent);
                            }
                        }
                    }
                }
            }
        }

        int cnt = count_components();
        cout << cnt << nl;
    }

    return 0;
}