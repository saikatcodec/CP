#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define int long long
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
   public:
    Graph(int vertices);
    void add_edge(int src, int dst);
    int count_paths(int src, int dst, int vertices);

   private:
    int m_vertices;
    list<int>* m_neighbours;
    void path_counter(int src, int dst, int& path_count,
                      vector<bool>& visited);
};

Graph::Graph(int vertices) {
    m_vertices = vertices;
    m_neighbours = new list<int>[vertices];
}

void Graph::add_edge(int src, int dst) {
    m_neighbours[src].push_back(dst);
}

int Graph::count_paths(int src, int dst, int vertices) {
    int path_count = 0;
    vector<bool> visited(vertices, false);
    path_counter(src, dst, path_count, visited);
    return path_count;
}

void Graph::path_counter(int src, int dst, int& path_count,
                         vector<bool>& visited) {
    visited[src] = true;
    if (src == dst) {
        path_count++;
    } else {
        for (auto neighbour : m_neighbours[src]) {
            if (!visited[neighbour])
                path_counter(neighbour, dst, path_count,
                             visited);
        }
    }
    visited[src] = false;
}

int32_t main() {
    FIO;

    testCase(t) {
        int n, v, k;
        cin >> n >> v >> k;

        Graph g = Graph(n);

        int s, t;
        cin >> s >> t;

        for (int i = 0; i < v; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            g.add_edge(x, y);
        }

        cout << g.count_paths(s, t, n) << nl;
    }

    return 0;
}