#include <bits/stdc++.h>
using namespace std;

int makePair(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    return 1 * makePair(n - 1) + (n - 1) * makePair(n - 2);
}

int main() {
    int n;
    cout << "N friends going to party with bike by single or double" << endl;
    cout << "Enter friends No: ";
    cin >> n;

    cout << "No of ways to go to party: ";
    cout << makePair(n) << endl;

    return 0;
}