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
        int n;
        cin >> n;

        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        int q;
        cin >> q;

        while (q--) {
            int l, r;
            cin >> l >> r;

            int ij = -1;
            for (int j = r; j >= l; j--) {
                if (ar[l - 1] != ar[j - 1]) {
                    ij = j;
                    break;
                }
            }

            if (ij == -1) {
                cout << "-1 -1" << nl;
            } else {
                cout << l << " " << ij << nl;
            }
        }

        cout << nl;
    }

    return 0;
}