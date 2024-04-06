#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define int long long
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

int a, b, c, d, e, f;
int arr[10002];

int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if (arr[n] > 0) {
        return arr[n];
    } else
        arr[n] = (fn(n - 1) + fn(n - 2) + fn(n - 3) + fn(n - 4) + fn(n - 5) +
                  fn(n - 6)) %
                 10000007;

    return arr[n];
}
int32_t main() {
    FIO;

    int n, cases;
    cin >> cases;
    for (int caseno = 1; caseno <= cases; ++caseno) {
        memset(arr, 0, sizeof(arr));
        cin >> a >> b >> c >> d >> e >> f >> n;
        cout << "Case " << caseno << ": " << fn(n) % 10000007 << nl;
    }
    return 0;
}