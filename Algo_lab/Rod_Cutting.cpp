#include <bits/stdc++.h>
using namespace std;

/**
 * Calculates the answer
 * @param price array of price 
 * @param len length of the rod
 * @param dp reference of the dp array(vector) to memoization
 * 
 * @return the price of specific length
 */
int rodCut(int price[], int len, vector<int> &dp) {
    if (dp[len] == INT_MIN) {
        int q = INT_MIN; // create a variable with the default value int_min

        // Cut the rod and check maximum price of every part of the rod
        for (int i = 1; i <= len; i++) {
            // To do the recursive call
            q = max(q, price[i - 1] + rodCut(price, len - i, dp));
        }

        // Set calculated value in the specific length
        dp[len] = q;
    }

    // Return the value of that length
    return dp[len];
}

int main() {
    // Length of the rod
    int len;
    cin >> len;

    // Lengthwise price of rod
    int price[len];
    for (int i = 0; i < len; i++) {
        cin >> price[i];
    }

    // Memoization of dynamic programming
    // dp array(Vector) size: length + 1 and has default value INT_MIN(-ve)
    vector<int> dp(len + 1, INT_MIN);
    dp[0] = 0; // length 0 has 0 value

    // Call the rodCut function
    cout << "Answer: " << rodCut(price, len, dp) << endl;

    return 0;
}