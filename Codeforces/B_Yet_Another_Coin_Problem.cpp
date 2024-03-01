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

int coins[] = {15, 10, 6, 3, 1};
int dp[100001] = {0};
int minCoins(int N, int M) {
    for (int i = 0; i <= N; i++) dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return dp[N];
}

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        int cnt = 0;
        if (n > 100000) {
            cnt = n / 15;
            n %= 15;
        }

        if (cnt > 0) {
            cnt -= 100;
            n = n + (100 * 15);
        }

        int ans = minCoins(n, 5);

        cout << ans + cnt << nl;
    }

    return 0;
}