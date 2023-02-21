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

        vector<vector<ll>> penInfo(n + 2, vector<ll>(3));
        for (ll i = 1; i <= n; i++) {
            ll a;
            cin >> a;
            penInfo[i] = {a, 1, -1};
        }

        ll q;
        cin >> q;

        while (q--) {
            ll cmd;
            cin >> cmd;

            if (cmd == 1) {
                ll x, y;
                cin >> x >> y;

                if (((penInfo[x][0] > penInfo[y][0]) && (penInfo[x][1] > 0) && (penInfo[y][1] > 0))) {
                    penInfo[x][0] += penInfo[y][0];
                    penInfo[y][0] = 0;
                    penInfo[x][1] += penInfo[y][1];
                    penInfo[y][1] = 0;
                    penInfo[y][2] = x;
                } else if ((penInfo[x][0] < penInfo[y][0]) && (penInfo[x][1] > 0) && (penInfo[y][1] > 0)) {
                    penInfo[y][0] += penInfo[x][0];
                    penInfo[x][0] = 0;
                    penInfo[y][1] += penInfo[x][1];
                    penInfo[x][1] = 0;
                    penInfo[x][2] = y;
                }
            } else if (cmd == 2) {
                ll x;
                cin >> x;

                cout << penInfo[x][1] << nl;
            } else if (cmd == 3) {
                ll x;
                cin >> x;

                cout << penInfo[x][2] << nl;
            }
        }
    }

    return 0;
}