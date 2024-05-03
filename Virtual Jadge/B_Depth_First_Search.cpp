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
vector<int> start, finish;
int cnt = 0;

void dfs(int src) {
    start[src] = ++cnt;

    for (auto p : adj[src]) {
        if (start[p] == 0) {
            dfs(p);
        }
    }

    finish[src] = ++cnt;
}

int main() {
    FIO;

    int n;
    cin >> n;

    adj.resize(n + 2);
    start.resize(n + 2, 0);
    finish.resize(n + 2, 0);

    for (int i = 0; i < n; i++) {
        int u, k;
        cin >> u >> k;

        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            adj[u].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (start[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << start[i] << " " << finish[i] << nl;
    }

    return 0;
}