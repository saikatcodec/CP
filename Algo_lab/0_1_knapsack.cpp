#include <bits/stdc++.h>
using namespace std;

int knpsk(int n, int w, int wt[], int p[]) {
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++) {
        for (int k = 0; k <= w; k++) {
            if (i == 0 || k == 0) {
                dp[i][k] = 0;
            } else if (wt[i - 1] <= k) {
                dp[i][k] = max(p[i - 1] + dp[i - 1][k - wt[i - 1]], dp[i - 1][k]);
            } else {
                dp[i][k] = dp[i - 1][k];
            }
        }
    }

    return dp[n][w];
}

int main() {
    int wt[] = {3, 4, 6, 5};
    int price[] = {2, 3, 1, 4};

    int n = 4, w = 8;

    cout << "Max value: " << knpsk(n, w, wt, price) << endl;

    return 0;
}