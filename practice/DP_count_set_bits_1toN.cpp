#include <bits/stdc++.h>
using namespace std;

int main() {
        int n;
    cin >> n;

    int dp[n + 1] = {0};
    dp[0] = 0;

    // order of O(N)
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i / 2] + (i & 1);
        cout << dp[i] << endl;
    }

    return 0;
}