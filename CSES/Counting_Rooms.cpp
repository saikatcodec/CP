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

int v;
vector<vector<int>> g(1000005);
vector<bool> visited(1000005, false);
vector<int> cmp;

void dfs_helper(int st) {
    visited[st] = true;

    for (auto ele : g[st]) {
        cmp.push_back(ele);
        if (!visited[ele]) {
            dfs_helper(ele);
        }
    }
}

void addEdges(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}

int hasRoom() {
    int cnt = 0;

    for (int i = 0; i <= v; i++) {
        if (!visited[i]) {
            dfs_helper(i);
        }
        if (!cmp.empty()) {
            cnt++;
            cmp.clear();
        }
    }

    return cnt;
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    string grid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    v = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                int cell = (i * m) + (j + 1);
                addEdges(cell, cell);
                if ((j + 1 < m) && (grid[i][j + 1] == '.')) {
                    addEdges(cell, cell + 1);
                }
                if ((i + 1 < n) && (grid[i + 1][j] == '.')) {
                    addEdges(cell, cell + m);
                }
            }
        }
    }

    cout << hasRoom() << nl;

    return 0;
}