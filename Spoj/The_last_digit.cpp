#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int lastDigit(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int ans = lastDigit(a, b / 2) % 10;
    if (b & 1) {
        return ((((ans % 10) * ans) % 10) * a) % 10;
    }

    return ((ans % 10) * ans) % 10;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        cout << lastDigit(a, b) << nl;
    }

    return 0;
}