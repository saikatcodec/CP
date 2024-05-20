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
vector<int> b;

void bfs(int src) {
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int frnt = q.front();
        q.pop();

        for (auto [u, a] : adj[frnt]) {
            if (b[u] == -1) {
                q.push(u);
                if (a != b[frnt]) {
                    b[u] = a;
                }
            }
        }
    }
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    adj.resize(n + 2);
    b.resize(n + 2, -1);

    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;

        adj[u].push_back({v, a});
        adj[v].push_back({u, a});
    }

    bfs(1);

    if (all_of(b.begin(), b.end(), [](int i) { return i == -1; })) {
        cout << -1 << nl;
    } else {
        for (int i = 1; i <= n; i++) {
            if (b[i] == -1) {
                cout << INT_MAX << " ";
            } else {
                cout << b[i] << " ";
            }
        }
        cout << nl;
    }

    return 0;
}