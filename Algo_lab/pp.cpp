#include <bits/stdc++.h>
using namespace std;

int rodCut(int price[], int len, int dp[]) {
    if (dp[len] == -1) {
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

    int dp[len+1];
    for(int i =0; i<=len; i++){
        dp[i]=-1;
    }
    dp[0] = 0;

    cout << "Answer: " << rodCut(price, len, dp) << endl;

    return 0;
}