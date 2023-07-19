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
vector<vector<ll>> tr(N);
vector<ll> leaf;
map<ll, ll> dist;

void dfs(ll src, ll prnt) {
    dist[src] = dist[prnt] + 1;
    if (tr[src].size() == 1) {
        leaf.push_back(src);
        return;
    }

    for (auto p : tr[src]) {
        if (p != prnt) {
            dfs(p, src);
        }
    }
}

int main() {
    FIO;

    ll n;
    cin >> n;

    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;

        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    double total = 0.0;
    dfs(1, 0);

    for (auto ele : leaf) {
        total += (dist[ele] - 1) * 1.0;
    }
    ll size = leaf.size();
    double ans = total / (size * 1.0);
    cout << ps(ans, 15) << nl;

    return 0;
}