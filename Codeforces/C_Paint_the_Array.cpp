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

        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll gm = 0;
        for (int i = 0; i < n; i += 2) {
            gm = __gcd(gm, arr[i]);
        }

        ll gg = 0;
        for (int i = 1; i < n; i += 2) {
            gg = __gcd(gg, arr[i]);
        }

        bool flag = true;

        if (gm == gg) {
            cout << 0 << nl;
        } else {
            if (gm == 1) {
                for (int i = 0; i < n; i += 2) {
                    if (arr[i] % gg == 0) {
                        flag = false;
                        break;
                    }
                }

                if (!flag) {
                    cout << 0 << nl;
                } else {
                    cout << gg << nl;
                }
            } else if (gg == 1) {
                for (int i = 1; i < n; i += 2) {
                    if (arr[i] % gm == 0) {
                        flag = false;
                        break;
                    }
                }

                if (!flag) {
                    cout << 0 << nl;
                } else {
                    cout << gm << nl;
                }
            } else {
                cout << max(gg, gm) << nl;
            }
        }
    }

    return 0;
}