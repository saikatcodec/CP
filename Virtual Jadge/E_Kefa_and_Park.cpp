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
vector<int> cats;
int ans = 0;

void dfs(int src, int parent, int m, int mc) {
    mc = cats[src] + mc;

    if (cats[src] == 0) {
        mc = 0;
    }

    if (mc > m) {
        return;
    }

    if ((adj[src].size() == 1) && *(adj[src].begin()) == parent) {
        ans++;
        return;
    }

    for (auto nd : adj[src]) {
        if (nd != parent) {
            dfs(nd, src, m, mc);
        }
    }
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    adj.resize(n + 2);
    cats.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, m, 0);
    cout << ans << nl;

    return 0;
}