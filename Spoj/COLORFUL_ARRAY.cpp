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

class Dsu {
    ll n;
    ll *parent, *rank;
    void makeSet() {
        for (ll i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

   public:
    Dsu(ll n) {
        this->n = n;
        parent = new ll[n];
        rank = new ll[n];
        makeSet();
    }

    ll findSet(ll a) {
        if (parent[a] == -1) {
            return a;
        }

        return parent[a] = findSet(parent[a]);
    }

    void unionSet(ll a, ll b) {
        a = findSet(a);
        b = findSet(b);

        if (a != b) {
            parent[a] = b;
        }
    }
};

int main() {
    FIO;

    ll n, q;
    cin >> n >> q;

    ll l[q], r[q], c[q];
    for (ll i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> c[i];
    }

    Dsu g = Dsu(n + 2);
    ll ans[n + 1] = {0};

    for (int i = q - 1; i >= 0; i--) {
        int index = g.findSet(l[i]);

        while (index <= r[i]) {
            ans[index] = c[i];
            g.unionSet(index, index + 1);
            index = g.findSet(index);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << nl;
    }

    return 0;
}