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

int v = 100005;
vector<vector<int>> adj(v);

void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs_helper(int src, vector<bool> &used) {
    used[src] = true;

    for (auto node : adj[src]) {
        if (!used[node]) {
            dfs_helper(node, used);
        }
    }
}

void dfs(int n) {
    vector<bool> used(n, false);
    int cnt = 0;
    vector<int> track;

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cnt++;
            track.push_back(i);
            dfs_helper(i, used);
        }
    }

    cnt--;
    if (cnt <= 0) {
        cout << 0 << nl;
    } else {
        cout << cnt << nl;

        for (int i = 0; i < cnt; i++) {
            if (i + 1 <= cnt) {
                cout << track[i] << " " << track[i + 1] << nl;
            }
        }
    }
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }

    dfs(n);

    return 0;
}