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

bool hasLeap(int y) {
    if (y % 400 == 0)
        return true;
    else if (y % 100 == 0)
        return false;
    else if (y % 4 == 0)
        return true;
    else
        return false;
}

int main() {
    FIO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int d, m, y, qy;
        cin >> d >> m >> y >> qy;

        int cnt = 0;
        if (d == 29 && m == 2) {
            while ((y <= qy)) {
                y++;
                if (y > qy) {
                    break;
                }
                if (hasLeap(y)) {
                    cnt++;
                }
            }
        } else {
            cnt = qy - y;
        }
        cout << "Case " << i << ": " << cnt << nl;
    }

    return 0;
}