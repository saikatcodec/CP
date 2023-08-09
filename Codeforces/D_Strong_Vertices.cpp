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

vector<vector<int>> adj(200004);

void addEdge(int a, int b) {
    adj[a].push_back(b);
}

void dfs_helper(int src, map<int, bool> &vst, int &cnt) {
    cnt++;
    vst[src] = true;

    for (auto node : adj[src]) {
        if (!vst[node]) {
            dfs_helper(node, vst, cnt);
        }
    }
}

map<int, int> dfs(int n) {
    map<int, int> cnts;
    for (int i = 1; i <= n; i++) {
        map<int, bool> vst;
        int cnt = -1;
        dfs_helper(i, vst, cnt);
        cnts[i] = cnt;
    }

    return cnts;
}

int main() {
    FIO;

    testCase(t) {
        adj.clear();
        adj.resize(200004);
        int n;
        cin >> n;

        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i - 1] - b[i - 1] > a[j - 1] - b[j - 1]) {
                    addEdge(i, j);
                } else if (a[i - 1] - b[i - 1] < a[j - 1] - b[j - 1]) {
                    addEdge(j, i);
                } else {
                    addEdge(i, j);
                    addEdge(j, i);
                }
            }
        }

        vector<int> ans;
        int cnt = 0;
        map<int, int> mp = dfs(n);

        for (auto m : mp) {
            // cerr << m.first << " " << m.second << nl;
            if (m.second == n - 1) {
                cnt++;
                ans.push_back(m.first);
            }
        }

        cout << cnt << nl;
        for (auto ele : ans) {
            cout << ele << " ";
        }
        cout << nl;
    }

    return 0;
}