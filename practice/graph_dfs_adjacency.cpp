#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph {
    unordered_map<T, list<T>> g;

    /**
     * @param st starting point of graph
     * @param visited the track of visited node
     */
    void dfs_helper(T st, unordered_map<T, bool> &visited) {
        // At first print the starting node
        cout << st << " ";
        // Set starting point as true in visited map
        visited[st] = true;

        // Traverse the adjacency list of the node such as 1: 3, 2, 5 
        for (auto node : g[st]) {
            // if neighbour of the st is not visited then we call DFS recursively and continued
            if (!visited[node]) {
                dfs_helper(node, visited);
            }
        }
    }

   public:
    // To add the edges
    void addEdges(T x, T y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // Main part of DFS
    void dfs(T st) {
        // To keep track of visited node 
        unordered_map<T, bool> visited;

        // Traverse all the node one by one and set the nodes value false as default
        for (auto node_pair : g) {
            visited[node_pair.first] = false;
        }

        // Call the DFS function to print the graph
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