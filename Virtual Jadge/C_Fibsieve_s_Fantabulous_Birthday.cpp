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

    int t, q = 0;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll col = ceil(sqrt(n * 1.0));
        ll col1 = floor(sqrt(n * 1.0));
        ll row;
        if ((n - col1 * col1) < (col * col - n)) {
            row = n - col1 * col1;
            col = col1 + 1;
            swap(row, col);
            if (col1 & 1) {
                swap(row, col);
            }
        } else {
            row = (col * col) - n;
            row++;
            if (col % 2 == 0) {
                swap(row, col);
            }
        }

        cout << "Case " << ++q << ": " << row << " " << col << nl;
    }

    return 0;
}