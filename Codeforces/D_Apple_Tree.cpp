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

#define N 200002
map<ll, list<ll>> tr;
ll leaf[N];

ll dfs(ll src, ll prnt) {
    auto p = tr[src];
    if (p.size() == 1 && (*p.begin()) == prnt) {
        return leaf[src] = 1;
    }

    ll val = 0;
    for (auto e : p) {
        if (e != prnt) {
            val += dfs(e, src);
        }
    }

    return leaf[src] = val;
}

int main() {
    FIO;

    testCase(t) {
        tr.clear();
        ll n;
        cin >> n;

        for (ll i = 0; i < n - 1; i++) {
            ll a, b;
            cin >> a >> b;

            tr[a].push_back(b);
            tr[b].push_back(a);
        }

        dfs(1, 0);

        ll q;
        cin >> q;

        while (q--) {
            ll x, y;
            cin >> x >> y;

            cout << leaf[x] * leaf[y] << nl;
        }
    }

    return 0;
}