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

    int n;
    cin >> n;

    ll x[n], h[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }

    ll cnt = 0, test = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1) {
            cnt++;
            continue;
        }

        test = max(x[i - 1], test);
        if (x[i] - h[i] > test) {
            cnt++;
        } else if (x[i] + h[i] < x[i + 1]) {
            test = x[i] + h[i];
            cnt++;
        }
    }

    cout << cnt << nl;

    return 0;
}