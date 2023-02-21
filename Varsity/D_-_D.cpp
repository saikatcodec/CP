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
// clang-format on
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    float a, b, c;
    while (cin >> a >> b >> c) {
        float s = (a + b + c) / 2.0;

        if (s < a || s < b || s < c) {
            cout << "-1" << nl;
            continue;
        }

        float ans = (4 / 3.0) * sqrt(s * (s - a) * (s - b) * (s - c));
        if (ans > 0)
            cout << ps(ans, 3) << nl;
        else
            cout << "-1" << endl;
    }

    return 0;
}