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
        int n, k;
        cin >> n >> k;

        if (n < k || (n & 1 && k % 2 == 0)) {
            cout << "NO" << nl;
        } else if (n % k == 0) {
            cout << "YES" << nl;
            int div = n / k;
            for (int i = 0; i < k; i++) {
                cout << div << " ";
            }
            cout << nl;
        } else if ((n % 2 == 0 && k % 2 == 0) || (n & 1 && k & 1)) {
            cout << "YES" << nl;

            for (int i = 0; i < k - 2; i++) {
                cout << "1 ";
            }

            int rem = n - ((1 * (k - 2) > 0 ? k - 2 : 0));
            int half = rem / 2;
            if (half == 0) {
                cout << half + 1 << nl;
            } else if (half & 1) {
                cout << half << " " << half << nl;
            } else {
                cout << half + 1 << " " << half - 1 << nl;
            }
        } else if (n % 2 == 0 && k & 1) {
            if (n / 2 < k) {
                cout << "NO" << nl;
            } else {
                cout << "YES" << nl;

                for (int i = 0; i < k - 2; i++) {
                    cout << "2 ";
                }

                int rem = n - ((k - 2) > 0 ? (2 * (k - 2)) : 0);
                int half = rem / 2;
                if (half & 1) {
                    cout << half + 1 << " " << half - 1 << nl;
                } else {
                    cout << half << " " << half << nl;
                }
            }
        }
    }

    return 0;
}