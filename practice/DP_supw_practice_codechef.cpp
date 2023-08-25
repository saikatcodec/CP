/**
 * @file DP_supw_practice_codechef.cpp
 * @link https://www.codechef.com/ZCOPRAC/problems/ZCO14002
 *
 * @copyright Copyright (c) 2023
 *
 */

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

int mt(int n, int arr[], vector<int> &dp) {
    if (n == 1 || n == 2 || n == 3) {
        return dp[n] = arr[n - 1];
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = min(min(mt(n - 1, arr, dp), mt(n - 2, arr, dp)), mt(n - 3, arr, dp)) + arr[n - 1];
    return dp[n];
}

int main() {
    FIO;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n + 1, -1);
    int ans = mt(n, arr, dp);
    cout << min(min(dp[n], dp[n - 1]), dp[n - 2]) << nl;

    return 0;
}