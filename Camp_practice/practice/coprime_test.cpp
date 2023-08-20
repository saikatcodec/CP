#include <bits/stdc++.h>
using namespace std;

int coPrime(int l, int r, int m) {
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (__gcd(i, m) == 1) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n, m, a;
    cin >> n >> m >> a;

    cout << coPrime(0, n - 1, m) << endl;
    cout << coPrime(a, n + a - 1, m) << endl;

    return 0;
}