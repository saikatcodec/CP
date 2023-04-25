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

#define N 100002
vector<ll> dist(N, inf);
vector<vector<pair<int, ll>>> adj(N);

void addEdges(int a, int b, ll c) {
    adj[a].push_back({b, c});
}

void dijsktra(int st) {
    set<pair<ll, int>> pq;

    dist[st] = 0;
    pq.insert({dist[st], st});

    while (!pq.empty()) {
        auto node = *(pq.begin());
        pq.erase(pq.begin());

        for (auto ele : adj[node.second]) {
            if (node.first + ele.second < dist[ele.first]) {
                auto p = pq.find({dist[ele.first], ele.first});
                if (p != pq.end()) {
                    pq.erase(p);
                }

                dist[ele.first] = node.first + ele.second;
                pq.insert({dist[ele.first], ele.first});
            }
        }
    }
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;

        cin >> a >> b >> c;
        addEdges(a, b, c);
    }

    dijsktra(1);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << nl;

    return 0;
}