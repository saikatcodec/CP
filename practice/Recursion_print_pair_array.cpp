#include <bits/stdc++.h>
using namespace std;

void printPair(int arr[], int n, int i) {
    if (i > n) {
        return;
    }

    cout << arr[i] << " " << arr[n] << '\n';
    printPair(arr, n - 1, i + 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printPair(arr, n - 1, 0);

    return 0;
}