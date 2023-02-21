#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph {
    unordered_map<T, list<T>> g;

    void dfs_helper(T st, unordered_map<T, bool> &visited) {
        cout << st << " ";
        visited[st] = true;

        for (auto node : g[st]) {
            if (!visited[node]) {
                dfs_helper(node, visited);
            }
        }
    }

   public:
    void addEdges(T x, T y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    void dfs(T st) {
        unordered_map<T, bool> visited;

        for (auto node_pair : g) {
            visited[node_pair.first] = false;
        }

        dfs_helper(st, visited);
        cout << endl;
    }
};

int main() {
    Graph<int> gp;

    int e;
    cout << "Enter vertices number: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        gp.addEdges(x, y);
    }

    int st;
    cout << "Enter starting point: ";
    cin >> st;

    gp.dfs(st);

    return 0;
}