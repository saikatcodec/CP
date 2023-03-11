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

class Graph {
    unordered_map<int, list<int>> g;

   public:
    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int bfs(int st) {
        queue<int> q;
        unordered_map<int, bool> vst;

        q.push(st);
        vst[st] = true;

        int ans = 1;
        while (!q.empty()) {
            int fnt = q.front();
            q.pop();

            for (auto ele : g[fnt]) {
                if (!vst[ele]) {
                    q.push(ele);
                    vst[ele] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    FIO;

    int t, q = 0;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string mp[m];
        for (int i = 0; i < m; i++) {
            cin >> mp[i];
        }

        Graph g;
        int cnt = 0;
        int prince = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cnt++;
                if (mp[i][j] == '.') {
                    if ((j + 1 < n) && (mp[i][j + 1] == '.' || mp[i][j + 1] == '@')) {
                        g.addEdge(cnt, cnt + 1);
                    }
                    if ((i + 1 < m) && (mp[i + 1][j] == '.' || mp[i + 1][j] == '@')) {
                        g.addEdge(cnt, cnt + n);
                    }
                } else if (mp[i][j] == '@') {
                    prince = cnt;
                    if ((j + 1 < n) && (mp[i][j + 1] == '.' || mp[i][j + 1] == '@')) {
                        g.addEdge(cnt, cnt + 1);
                    }
                    if ((i + 1 < m) && (mp[i + 1][j] == '.' || mp[i + 1][j] == '@')) {
                        g.addEdge(cnt, cnt + n);
                    }
                }
            }
        }

        int ans = g.bfs(prince);
        cout << "Case " << ++q << ": " << ans << nl;
    }

    return 0;
}