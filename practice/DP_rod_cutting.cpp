#include <bits/stdc++.h>
using namespace std;

vector<int> price;
vector<int> memo;

int rodCut(int i) {
    if (i == 0) {
        return 0;
    }

    if (memo[i] != INT_MIN) return memo[i];

    int &ans = memo[i];
    ans = INT_MIN;
    for (int k = 1; k <= i; k++) {
        ans = max(ans, price[k - 1] + rodCut(i - k));
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    price.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    memo.clear();
    memo.resize(n + 1, INT_MIN);

    cout << rodCut(n) << '\n';

    return 0;
}