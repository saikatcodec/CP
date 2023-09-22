#include <bits/stdc++.h>
using namespace std;

void findSubsets(string inpt, char outpt[], int i, int j) {
    // Base case
    if (inpt[i] == '\0') {
        outpt[j] = '\0';
        if (outpt[0] == '\0') {
            cout << "NULL" << endl;
        }
        cout << outpt << endl;
        return;
    }

    // Rec case
    // Inclusive
    outpt[j] = inpt[i];
    findSubsets(inpt, outpt, i + 1, j + 1);
    // Exclusive
    findSubsets(inpt, outpt, i + 1, j);
}

int main() {
    string inpt;
    char outpt[100];
    cin >> inpt;

    findSubsets(inpt, outpt, 0, 0);

    return 0;
}