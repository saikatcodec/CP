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

    int m, s;
    cin >> m >> s;

    if (s == 0) {
        if (m == 1) {
            cout << "0 0" << nl;
            return 0;
        } else {
            cout << "-1 -1" << nl;
            return 0;
        }
    }

    string maxA, minA;
    for (int i = 0; i < m; i++) {
        int dig = min(9, s);
        maxA.push_back('0' + dig);
        s -= dig;
    }

    if (s > 0) {
        cout << "-1 -1" << nl;
        return 0;
    }

    minA = maxA;
    reverse(minA.begin(), minA.end());

    int j = 0;
    while (minA[j] == '0') {
        j++;
    }
    minA[0]++;
    minA[j]--;

    cout << minA << " " << maxA << nl;

    return 0;
}