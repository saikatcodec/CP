#include <bits/stdc++.h>
using namespace std;

void extractDigit(int n) {
    if (n == 0) {
        return;
    }
    extractDigit(n / 10);

    if (n % 10 == 1) {
        cout << "One ";
    } else if (n % 10 == 2) {
        cout << "Two ";
    } else if (n % 10 == 3) {
        cout << "Three ";
    } else if (n % 10 == 4) {
        cout << "Four ";
    } else if (n % 10 == 5) {
        cout << "Five ";
    } else if (n % 10 == 6) {
        cout << "Six ";
    } else if (n % 10 == 7) {
        cout << "Seven ";
    } else if (n % 10 == 8) {
        cout << "Eight ";
    } else if (n % 10 == 9) {
        cout << "Nine ";
    } else if (n % 10 == 0) {
        cout << "Zero ";
    }
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    extractDigit(n);
    cout << endl;

    return 0;
}