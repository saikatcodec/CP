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
    int v;
    list<pair<int, int>> ed;
    int *parent, *rank;

    void makeSet() {
        for (int i = 0; i < v; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

   public:
    Graph(int v) {
        this->v = v;
        parent = new int[v];
        rank = new int[v];

        makeSet();
    }

    ~Graph() {
        delete[] parent;
        delete[] rank;
    }

    void addEdge(int a, int b) {
        ed.push_back({a, b});
    }

    int findSet(int i) {
        if (parent[i] == -1) {
            return i;
        }

        return parent[i] = findSet(parent[i]);
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a != b) {
            if (a < b) {
                swap(a, b);
            }

            parent[b] = a;
            rank[a] += rank[b];
        }
    }

    int pairing() {
        int ans = 0;

        for (auto p : ed) {
            int s1 = findSet(p.first);
            int s2 = findSet(p.second);

            unionSet(s1, s2);
        }

        for (int i = 0; i < v; i++) {
            ans += (v - rank[findSet(i)]);
        }

        return ans / 2;
    }
};

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    Graph gp = Graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        gp.addEdge(a, b);
    }

    cout << gp.pairing() << nl;

    return 0;
}