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
// clang-format on
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Graph {
    unordered_map<int, list<int>> gp;
    int ver;

    void dfs(int st, unordered_map<int, bool> &visited) {
        visited[st] = true;

        for (auto ele : gp[st]) {
            if (!visited[ele]) {
                dfs(ele, visited);
            }
        }
    }

   public:
    Graph(int n) {
        this->ver = n;
    }

    void addEdges(int a, int b) {
        gp[a].push_back(b);
        gp[b].push_back(a);
    }

    int connected_components() {
        unordered_map<int, bool> visited;
        for (int i = 1; i <= ver; i++) {
            visited[i] = false;
        }

        int comp = 0;

        for (auto ele : visited) {
            if (!ele.second) {
                comp++;
                dfs(ele.first, visited);
            }
        }

        return comp;
    }
};

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        g.addEdges(a, b);
    }

    cout << m - n + g.connected_components() << nl;

    return 0;
}