#include <bits/stdc++.h>
using namespace std;

int sumPair(int n, int x) {
    if (n <= 1) {
        return n;
    }

    int tmp = pow(x, n - 1) + sumPair(n - 1, x);
    return tmp;
}

int main() {
    int n, x;
    cin >> x >> n;

    cout << sumPair(n, x) << '\n';

    return 0;
}