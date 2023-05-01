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

#define N 100001
vector<ll> parent(N, -1);
vector<ll> dist(N, inf);
vector<vector<pair<ll, ll>>> adj(N);

void addEdges(ll a, ll b, ll c) {
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
}

void dijkstra(ll src) {
    set<pair<ll, ll>> p;

    dist[src] = 0;
    p.insert({dist[src], src});

    while (!p.empty()) {
        auto frnt = *(p.begin());
        p.erase(p.begin());

        for (auto ele : adj[frnt.second]) {
            if (dist[frnt.second] + ele.second < dist[ele.first]) {
                auto t = p.find({dist[ele.first], ele.first});
                if (t != p.end()) {
                    p.erase(t);
                }

                dist[ele.first] = dist[frnt.second] + ele.second;
                p.insert({dist[ele.first], ele.first});
                parent[ele.first] = frnt.second;
            }
        }
    }
}

vector<ll> getPath(ll src, ll dest) {
    vector<ll> path;

    while (parent[dest] != -1) {
        path.push_back(dest);
        dest = parent[dest];
    }

    path.push_back(src);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    FIO;

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        addEdges(a, b, c);
    }

    dijkstra(1);

    if (dist[n] == inf) {
        cout << -1 << nl;
    } else {
        vector<ll> path = getPath(1, n);
        for (auto ele : path) {
            cout << ele << " ";
        }
        cout << nl;
    }

    return 0;
}