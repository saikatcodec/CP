#include <bits/stdc++.h>
using namespace std;

int rodCut(int price[], int len, vector<int> &dp) {
    if (dp[len] == INT_MIN) {
        int q = INT_MIN; 
        for (int i = 1; i <= len; i++) {
            q = max(q, price[i - 1] + rodCut(price, len - i, dp));
        }

        dp[len] = q;
    }

    return dp[len];
}

int main() {
    int len;
    cin >> len;

    int price[len];
    for (int i = 0; i < len; i++) {
        cin >> price[i];
    }

    vector<int> dp(len + 1, INT_MIN);
    dp[0] = 0;

    cout << "Answer: " << rodCut(price, len, dp) << endl;

    return 0;
}