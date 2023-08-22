#include <bits/stdc++.h>
using namespace std;

void printSeries(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    printSeries(n - 1);

    if (n == 2) {
        cout << " + x";
    } else {
        cout << " + x^" << n - 1;
    }
}

int main() {
    int n;
    cin >> n;

    printSeries(n);

    return 0;
}