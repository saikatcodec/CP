#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    list<pair<int, int>> edges;
    int *parent;

    void makeSet() {
        for (int i = 1; i <= v; i++) {
            parent[i] = -1;
        }
    }

   public:
    Graph(int v) {
        this->v = v;
        this->parent = new int[v + 1];
        makeSet();
    }

    void addEdges(int a, int b) {
        edges.push_back({a, b});
    }

    int findSet(int i) {
        // Base case
        if (parent[i] == -1) {
            return i;
        }

        // !Path compression
        return parent[i] = findSet(parent[i]);
    }

    void unionSet(int a, int b) {
        int s1 = findSet(a);
        int s2 = findSet(b);

        if (s1 != s2) {
            parent[b] = a;
        }
    }

    bool containsCycle() {
        int parent[v + 1];
        for (int i = 1; i <= v; i++) {
            parent[i] = -1;
        }
        for (auto p : edges) {
            int s1 = findSet(p.first);
            int s2 = findSet(p.second);

            if (s1 != s2) {
                unionSet(s1, s2);
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Graph gp = Graph(4);

    gp.addEdges(1, 2);
    gp.addEdges(2, 3);
    gp.addEdges(3, 4);
    gp.addEdges(4, 1);

    cout << gp.containsCycle() << endl;

    return 0;
}
