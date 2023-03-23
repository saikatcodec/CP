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
        ll n;
        cin >> n;

        ll c[n];
        for (ll i = 0; i < n; i++) {
            cin >> c[i];
        }

        sort(c, c + n);

        if (n >= 2 && c[0] == 1 && c[1] == 1) {
            ll subSum = 0;
            bool flag = true;
            for (int i = 0; i < n - 1; i++) {
                subSum += c[i];
                if (c[i + 1] > subSum) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        } else {
            if (c[0] == 1 && n == 1) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }

    return 0;
}