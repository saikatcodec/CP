#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    vector<int> parent, rank;
    void init(int n) {
        parent.clear();
        parent.resize(n + 1);
        rank.clear();
        rank.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int findSet(int a) {
        if (parent[a] == -1) {
            return a;
        }

        return parent[a] = findSet(parent[a]);
    }

    void unite(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }

            parent[b] = a;
            rank[a] += rank[b];
        }
    }
};

int main() {
    int vertexNum, edgesNum;
    cin >> vertexNum >> edgesNum;

    vector<vector<int>> edges(edgesNum + 1, vector<int>(3));
    for (int i = 0; i < edgesNum; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        edges[i] = {w, x, y};
    }

    sort(edges.begin(), edges.end());

    Dsu g;
    g.init(vertexNum);

    int ans = 0;
    for (int i = 0; i < edgesNum; i++) {
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];

        if (g.findSet(x) != g.findSet(y)) {
            g.unite(x, y);
            ans += w;
        }
    }

    cout << ans << endl;

    return 0;
}