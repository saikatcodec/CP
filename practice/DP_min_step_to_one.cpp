#include <bits/stdc++.h>
using namespace std;

int minStep(int n) {
    int dp[100] = {0};

    for (int i = 2; i <= n; i++) {
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        if (i % 3 == 0) {
            x = dp[i / 3];
        }
        if (i % 2 == 0) {
            y = dp[i / 2];
        }
        z = dp[i - 1];

        dp[i] = min(min(x, y), z) + 1;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << minStep(n) << endl;

    return 0;
}