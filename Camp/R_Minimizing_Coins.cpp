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

int minCo(int coins[], int n, int x) {
    int dp[x + 1] = {0};

    for (int c = 1; c <= x; c++) {
        int tmp = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (coins[i] <= c) {
                tmp = min(tmp, dp[c - coins[i]] + 1);
            }
        }

        dp[c] = tmp;
    }

    return dp[x];
}

int32_t main() {
    FIO;

    int n, x;
    cin >> n >> x;

    int coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int ans = minCo(coins, n, x);
    if (ans == INT_MAX || x == 0) {
        cout << -1 << nl;
    } else {
        cout << ans << nl;
    }

    return 0;
}