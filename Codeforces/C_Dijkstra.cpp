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

#define N 100001
vector<int> parent(N, -1);
vector<int> dist(N, INT_MAX);
vector<vector<pair<int, int>>> adj(N);

void addEdges(int a, int b, int c) {
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
}

void dijkstra(int src) {
    unordered_set<int> p;

    dist[src] = 0;
    p.insert( src);

    while (!p.empty()) {
        auto frnt = *(p.begin());
        p.erase(p.begin());

        for (auto ele : adj[frnt]) {
            if (dist[frnt] + ele.second < dist[ele.first]) {
                dist[ele.first] = dist[frnt] + ele.second;
                p.insert(ele.first);
                parent[ele.first] = frnt;
            }
        }
    }
}

vector<int> getPath(int src, int dest) {
    vector<int> path;

    while (parent[dest] != -1) {
        path.push_back(dest);
        dest = parent[dest];
    }

    path.push_back(src);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        addEdges(a, b, c);
    }

    dijkstra(1);

    if (dist[n] == INT_MAX) {
        cout << -1 << nl;
    } else {
        vector<int> path = getPath(1, n);
        for (auto ele : path) {
            cout << ele << " ";
        }
        cout << nl;
    }

    return 0;
}