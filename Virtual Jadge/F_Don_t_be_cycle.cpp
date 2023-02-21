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

int parent[200005];
int rankBy[200005];
int ans;

struct dsu {
    void init(int n) {
        for (int i = 0; i < n + 5; i++) {
            parent[i] = -1;
            rankBy[i] = 1;
        }
    }

    int find(int a) {
        if (parent[a] == -1) {
            return a;
        }

        return parent[a] = (find(parent[a]));
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            if (rankBy[a] < rankBy[b]) {
                swap(a, b);
            }
            parent[b] = a;
            rankBy[a] += rankBy[b];
        } else {
            ans++;
        }
    }
};

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    dsu ds;
    ds.init(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        ds.unite(a, b);
    }

    cout << ans << nl;

    return 0;
}