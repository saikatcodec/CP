#include <bits/stdc++.h>
using namespace std;

string word[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

void extractDigit(int n) {
    if (n == 0) {
        return;
    }
    extractDigit(n / 10);
    cout << word[n % 10] << " ";
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    extractDigit(n);
    cout << endl;

    return 0;
}