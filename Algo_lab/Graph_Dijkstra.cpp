#include <bits/stdc++.h>
using namespace std;

#define N 10005
vector<int> dist(N, INT_MAX);
vector<int> parent(N, -1);
vector<vector<pair<int, int>>> adj(N);

void addEdges(int a, int b, int c) {
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
}

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty()) {
        int frnt = pq.top().second;
        pq.pop();

        for (auto ele : adj[frnt]) {
            if (ele.second + dist[frnt] < dist[ele.first]) {
                dist[ele.first] = ele.second + dist[frnt];
                pq.push({dist[ele.first], ele.first});
            }
        }
    }
}

int main() {
    freopen("Graph.txt", "r", stdin);
    
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        addEdges(a, b, c);
    }

    dijkstra(2);
    cout << dist[4] << endl;

    return 0;
}