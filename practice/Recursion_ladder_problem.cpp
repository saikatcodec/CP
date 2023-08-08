#include <bits/stdc++.h>
using namespace std;

int cntStep(int n, int k) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += cntStep(n - i, k);
    }

    return ans;
}

int main() {
    int n, k;
    cout << "Enter N(steps) and K(jumps): ";
    cin >> n >> k;

    cout << "No ways: ";
    cout << cntStep(n, k) << endl;

    return 0;
}