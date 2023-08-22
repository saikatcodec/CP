#include <bits/stdc++.h>
using namespace std;

void printReverse(int arr[], int n) {
    if (n <= 0) {
        return;
    }

    cout << arr[n - 1] << " ";
    printReverse(arr, n - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    printReverse(arr, n);

    return 0;
}