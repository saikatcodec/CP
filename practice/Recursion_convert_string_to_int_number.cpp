#include <bits/stdc++.h>
using namespace std;

int convert(string s, int n) {
    if (n == 1) {
        return s[0] - '0';
    }

    int rem = convert(s, n - 1);
    return 10 * rem + (s[n - 1] - '0');
}

int main() {
    string sNum;
    cout << "Enter number: ";
    cin >> sNum;

    cout << convert(sNum, sNum.size()) << endl;

    return 0;
}