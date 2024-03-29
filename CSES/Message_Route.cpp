#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define nl "\n"
#define ll long long
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int v = 100002;
vector<vector<int>> adj(v);
vector<int> par(v, -1);
vector<int> dist(v, 0);

void addEdges(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool bfs(int src, int dest) {
    vector<bool> used(v, false);
    queue<int> q;

    used[src] = true;
    q.push(src);

    while (!q.empty()) {
        int frnt = q.front();
        q.pop();

        for (auto ele : adj[frnt]) {
            if (!used[ele]) {
                q.push(ele);
                used[ele] = true;

                dist[ele] = dist[frnt] + 1;
                par[ele] = frnt;

                if (ele == dest) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        addEdges(a, b);
    }

    if (!bfs(1, n)) {
        cout << "IMPOSSIBLE" << nl;
    } else {
        vector<int> path;

        int len = n;
        while (len != -1) {
            path.push_back(len);
            len = par[len];
        }

        reverse(path.begin(), path.end());

        cout << path.size() << nl;
        for (auto ele : path) {
            cout << ele << " ";
        }
        cout << nl;
    }

    return 0;
}