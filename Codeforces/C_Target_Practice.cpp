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
        string str[10];
        for (int i = 0; i < 10; i++) {
            cin >> str[i];
        }

        int ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (str[i][j] == 'X') {
                    int minE = min(i + 1, j + 1);
                    int maxE = max(i + 1, j + 1);
                    if (minE == 1 or maxE == 10) {
                        ans += 1;
                    } else if (minE == 2 or maxE == 9) {
                        ans += 2;
                    } else if (minE == 3 or maxE == 8) {
                        ans += 3;
                    } else if (minE == 4 or maxE == 7) {
                        ans += 4;
                    } else if (minE == 5 or maxE == 6) {
                        ans += 5;
                    }
                }
            }
        }

        cout << ans << nl;
    }

    return 0;
}