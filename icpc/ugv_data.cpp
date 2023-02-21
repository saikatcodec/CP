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

int main() {
    FIO;

    ll t;
    cin >> t;
    int qu = 0;

    while (t--) {
        ll n, m, a, b, c, i, s, t;
        cin >> n >> m >> s >> t;
        ll path[n + 2], from[n + 2];
        vector<pair<ll, ll>> ve[n + 1];
        vector<ll> ans;
        for (i = 0; i < m; i++) {
            cin >> a >> b >> c;
            ve[a].push_back({b, c});
            ve[b].push_back({a, c});
        }
        unordered_set<int> q;
        q.insert(s);
        for (i = 0; i < n + 2; i++) path[i] = 10000000000000;
        path[s] = 0;
        while (!q.empty()) {
            ll u = *q.begin();
            q.erase(q.begin());
            for (auto x : ve[u]) {
                if (path[u] + x.second < path[x.first]) {
                    path[x.first] = path[u] + x.second;
                    from[x.first] = u;
                    q.insert(x.first);
                }
            }
        }
        if (path[t] == 10000000000000) {
            cout << "Case #" << ++qu << ": unreachable" << nl;
        } else {
          cout << "Case #" << ++qu << ": " << path[t] << nl;
        }
    }

    return 0;
}