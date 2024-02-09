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

int main() {
    FIO;

    testCase(t) {
        int n, m, k;
        cin >> n >> m >> k;

        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        set<int> as, bs;
        for (int i = 0; i < n; i++) {
            if (a[i] <= k) {
                as.insert(a[i]);
            }
        }
        for (int i = 0; i < m; i++) {
            if (b[i] <= k) {
                bs.insert(b[i]);
            }
        }

        int len = k / 2;
        if (as.size() >= len && bs.size() >= len) {
            as.merge(bs);
            if (as.size() == k) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}