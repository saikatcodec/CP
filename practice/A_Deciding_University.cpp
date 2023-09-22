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
vector<int> dist(100005, 0);

void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void bfs(int src) {
    dist[src] = 0;
    queue<int> q;
    map<int, bool> vst;
    vst[src] = true;
    q.push(src);

    while (!q.empty()) {
        int fnt = q.front();
        q.pop();

        for (auto nd : adj[fnt]) {
            if (!vst[nd]) {
                q.push(nd);
                dist[nd] = dist[fnt] + 1;
                vst[nd] = true;
            }
        }
    }
}

int main() {
    FIO;

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        addEdge(a, b);
    }

    bfs(1);

    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
        st.insert({dist[i], adj[i].size()});
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (st.find({a, b}) != st.end()) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}