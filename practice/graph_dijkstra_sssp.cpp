#include <bits/stdc++.h>
using namespace std;

class Graph {
    unordered_map<int, list<pair<int, int>>> g;
    unordered_map<int, int> dist, p;

   public:
    void addEdges(int a, int b, int w) {
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    void dijkstra(int st) {
        priority_queue<pair<int, int>> pq;
        for (auto nodes : g) {
            dist[nodes.first] = INT_MAX;
            p[nodes.first] = -1;
        }

        dist[st] = 0;
        pq.push({dist[st], st});

        while (!pq.empty()) {
            auto fnt = pq.top();
            pq.pop();

            for (auto n : g[fnt.second]) {
                if (fnt.first + n.second < dist[n.first]) {
                    dist[n.first] = fnt.first + n.second;
                    pq.push({dist[n.first], n.first});
                    p[n.first] = fnt.second;
                }
            }
        }
    }

    void printShortPath() {
        for (auto l : dist) {
            cout << l.first << " located at distance " << l.second << endl;
        }
    }

    vector<int> getShortestPath(int src, int dest) {
        vector<int> path;

        while (p[dest] != -1) {
            path.push_back(dest);
            dest = p[dest];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {
    Graph g;

    g.addEdges(1, 2, 1);
    g.addEdges(1, 3, 3);
    g.addEdges(1, 4, 7);
    g.addEdges(2, 3, 1);
    g.addEdges(3, 4, 2);
    g.dijkstra(1);
    g.printShortPath();

    vector<int> path = g.getShortestPath(1, 3);
    for (auto p : path) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}