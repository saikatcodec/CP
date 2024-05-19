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
vector<int> dist;

void bfs(int src) {
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int fnt = q.front();
        q.pop();

        for (auto nd : adj[fnt]) {
            if (dist[fnt] + 1 < dist[nd]) {
                dist[nd] = dist[fnt] + 1;
                q.push(nd);
            }
        }
    }
}

int main() {
    FIO;

    int n;
    cin >> n;

    adj.resize(n + 2);
    dist.resize(n + 2, INT_MAX);

    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;

        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;

            adj[u].push_back(v);
        }
    }

    bfs(1);

    for (int i = 1; i <= n; i++) {
        cout << i << " " << ((dist[i] == INT_MAX) ? -1 : dist[i]) << nl;
    }

    return 0;
}