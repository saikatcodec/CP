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

int v = 1000005, N;
vector<vector<int>> adj(v);
vector<int> par(v, -1), dist(v, 0);

void addEdges(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool bfs(int src, int dest) {
    vector<bool> used(v, false);
    queue<int> q;

    q.push(src);
    used[src] = true;

    while (!q.empty()) {
        int frnt = q.front();
        q.pop();

        for (auto ele : adj[frnt]) {
            if (!used[ele]) {
                q.push(ele);
                dist[ele] = dist[frnt] + 1;
                par[ele] = frnt;
                used[ele] = true;

                if (ele == dest) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    N = n * m;

    string grid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int src, dest;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cell = (i * m) + (j + 1);
            if (grid[i][j] == '#') {
                continue;
            }
            if (grid[i][j] == 'A') {
                src = cell;
            } else if (grid[i][j] == 'B') {
                dest = cell;
            }
            addEdges(cell, cell);
            if (j + 1 < m && grid[i][j + 1] != '#') {
                addEdges(cell, cell + 1);
            }
            if (i + 1 < n && grid[i + 1][j] != '#') {
                addEdges(cell, cell + m);
            }
        }
    }

    if (!bfs(src, dest)) {
        cout << "NO" << nl;
    } else {
        vector<int> path;
        int len = dest;

        while (dest != -1) {
            path.push_back(dest);
            dest = par[dest];
        }

        reverse(path.begin(), path.end());

        cout << "YES" << nl;
        cout << dist[len] << nl;
        for (auto ele : path) {
            if (ele == src) {
                continue;
            } else if (src - 1 == ele) {
                cout << "L";
            } else if (src + 1 == ele) {
                cout << "R";
            } else if (src - m == ele) {
                cout << "U";
            } else if (src + m == ele) {
                cout << "D";
            }
            src = ele;
        }
        cout << nl;
    }

    return 0;
}