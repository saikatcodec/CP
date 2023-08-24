#include <bits/stdc++.h>
using namespace std;

// top down approch
int minCoins(int coins[], int n, int c, int dp[]) {
    if (c == 0) {
        return 0;
    }

    if (dp[c] != 0) {
        return dp[c];
    }

    int tmp = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (c - coins[i] >= 0) {
            tmp = min(tmp, minCoins(coins, n, c - coins[i], dp) + 1);
        }
    }

    return dp[c] = tmp;
}

// bottom up approch
int minCoinsBU(int coins[], int n, int c) {
    int dp[c + 1] = {0};

    for (int i = 1; i <= c; i++) {
        int tmp = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                tmp = min(tmp, dp[i - coins[j]] + 1);
            }
        }
        dp[i] = tmp;
    }

    return dp[c];
}

int main() {
    int coins[] = {1, 7, 10};
    int n = sizeof(coins) / sizeof(coins[0]);

    int c;
    cin >> c;
    int dp[c + 1] = {0};

    cout << minCoins(coins, n, c, dp) << endl;
    cout << minCoinsBU(coins, n, c) << endl;

    return 0;
}