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
vector<bool> vis;

void dfs(int src, int &cnt, int &amnt, int money[]) {
    vis[src] = true;
    cnt += money[src];
    amnt++;

    for (auto nd : adj[src]) {
        if (!vis[nd]) {
            dfs(nd, cnt, amnt, money);
        }
    }
}

int main() {
    FIO;

    int c = 0;
    testCase(t) {
        adj.clear();
        vis.clear();

        int n, m;
        cin >> n >> m;

        adj.resize(n + 2);
        vis.resize(n + 2, false);

        int money[n + 1];
        for (int i = 1; i <= n; i++) {
            cin >> money[i];
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        set<int> st;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int cnt = 0, amnt = 0;
                dfs(i, cnt, amnt, money);

                if (cnt % amnt == 0) {
                    st.insert(cnt / amnt);
                } else {
                    st.insert(-1);
                }
            }
        }

        if (st.size() == 1 && (*st.begin() != -1)) {
            cout << "Case " << ++c << ": Yes" << nl;
        } else {
            cout << "Case " << ++c << ": No" << nl;
        }
    }

    return 0;
}