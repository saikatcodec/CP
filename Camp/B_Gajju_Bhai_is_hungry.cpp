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
vector<int> lev(1000002, 0);

void bfs(int src) {
    lev[src] = 0;
    queue<int> q;
    map<int, bool> vst;
    vst[src] = true;
    q.push(src);

    while (!q.empty()) {
        int fnt = q.front();
        q.pop();

        for (auto ele : adj[fnt]) {
            if (!vst[ele]) {
                lev[ele] = lev[fnt] + 1;
                vst[ele] = true;
                q.push(ele);
            }
        }
    }
}

int main() {
    FIO;

    testCase(t) {
        adj.clear(), lev.clear();
        adj.resize(1000002);
        lev.resize(1000002, 0);

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int rest[m];
        for (int i = 0; i < m; i++) {
            cin >> rest[i];
        }

        bfs(1);
        double ans = 0;
        for (int i = 0; i < m; i++) {
            ans += (2 * lev[rest[i]] * (1.00 / m));
        }

        cout << ps(ans, 6) << nl;
    }

    return 0;
}