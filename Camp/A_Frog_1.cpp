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

int dp[100002];
void frog(int arr[], int n) {
    dp[0] = dp[1] = 0;
    dp[2] = abs(arr[0] - arr[1]);

    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + abs(arr[i - 1] - arr[i - 2]), dp[i - 2] + abs(arr[i - 1] - arr[i - 3]));
    }
}

int main() {
    FIO;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    frog(arr, n);
    cout << dp[n] << nl;

    return 0;
}