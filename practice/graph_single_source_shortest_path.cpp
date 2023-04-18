#include <bits/stdc++.h>
using namespace std;

class Graph {
    map<int, list<int>> gp;
    map<int, bool> visited;
    map<int, int> dist;
    map<int, int> parent;
    int V;

   public:
    Graph(int v) {
        this->V = v;

        for (int i = 1; i <= v; i++) {
            parent[i] = -1;
        }
    }

    void addEdges(int a, int b) {
        gp[a].push_back(b);
        gp[b].push_back(a);
    }

    void bfs(int st) {
        queue<int> q;

        q.push(st);
        visited[st] = true;

        while (!q.empty()) {
            int fnt = q.front();
            q.pop();
            // cout << fnt << " ";

            for (auto n : gp[fnt]) {
                if (!visited[n]) {
                    q.push(n);
                    dist[n] += (dist[fnt] + 1);
                    parent[n] = fnt;
                    visited[n] = true;
                }
            }
        }
    }

    int getDist(int node) {
        return dist[node];
    }

    vector<int> getPath(int a, int b) {
        bfs(a);

        vector<int> path;
        while (parent[b] != -1) {
            path.push_back(b);
            b = parent[b];
        }
        path.push_back(a);

        reverse(path.begin(), path.end());

        return path;
    }
};

int main() {
    freopen("graph.txt", "r", stdin);

    int n, m;
    // cout << "Enter vertex number: ";
    cin >> m;
    // cout << "Enter edges number: ";
    cin >> n;

    Graph g(m);
    // cout << "Enter edge one by one:" << endl;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdges(a, b);
    }

    // cout << "BFS ";
    // g.bfs(2, 8);
    // cout << endl;

    cout << "Distance of 9 " << g.getDist(9) << endl;

    vector<int> path = g.getPath(3, 8);
    cout << "Shortest Path are: ";
    for (auto ele : path) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}