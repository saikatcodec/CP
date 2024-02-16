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

vector<vector<int>> adj(100005);
vector<int> team;

void addEdges(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool bfs(int src, vector<bool> &used) {
    bool flag = true;
    queue<int> q;

    q.push(src);
    used[src] = true;
    team[src] = 1;

    while (!q.empty()) {
        int frnt = q.front();
        q.pop();

        for (auto node : adj[frnt]) {
            if (team[frnt] == team[node]) {
                flag = false;
            }
            if (!used[node]) {
                if (team[frnt] == 1) {
                    team[node] = 2;
                } else {
                    team[node] = 1;
                }
                q.push(node);
                used[node] = true;
            }
        }
    }

    return flag;
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    team.resize(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        addEdges(a, b);
    }

    bool flag = true;
    vector<bool> used(n + 2, false);
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            flag = flag && bfs(i, used);
        }
    }

    if (flag) {
        for (int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
        cout << nl;
    } else {
        cout << "IMPOSSIBLE" << nl;
    }

    return 0;
}