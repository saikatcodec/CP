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

int firstCh(int n) {
    int tmp = 0;
    while (n > 0) {
        tmp = n % 10;
        n /= 10;
    }

    return tmp;
}

int main() {
    FIO;

    int n;
    cin >> n;

    if (n <= 9) {
        cout << n + 1 << nl;
    } else {
        int digit = log10(n) + 1;
        int ans = (digit - 1) * 10;

        int tmp = 0, k = 1;
        int fch = firstCh(n);
        while (k <= digit) {
            tmp = tmp * 10 + fch;
            k++;
        }

        if (tmp <= n) {
            ans += fch;
        } else {
            ans += (fch - 1);
        }

        cout << ans << nl;
    }

    return 0;
}