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

int bigMod(int x, int y, int n) {
    if (y == 0) {
        return 1;
    }

    x %= n;
    int ans = 0;
    ans = bigMod(x, y / 2, n);
    if (y % 2 == 0) {
        ans = ((ans % n) * ans) % n;
    } else if (y & 1) {
        ans = (((ans % n) * ans) % n * x) % n;
    }

    return ans;
}

int main() {
    FIO;

    int c;
    cin >> c;

    while (c--) {
        int x, y, n;
        cin >> x >> y >> n;

        int ans = bigMod(x, y, n);
        cout << ans << nl;
    }

    return 0;
}