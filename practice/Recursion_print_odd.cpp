#include <bits/stdc++.h>
using namespace std;

/*
// Worst solution
void removeOdd(int arr[], int n) {
    if (n <= 0) {
        return;
    }

    if (arr[n - 1] & 1) {
        arr[n - 1] = -1;
    }
    removeOdd(arr, n - 1);
}
*/

void removeOdd(int arr[], int &n, int i, int j) {
    if (i == n) {
        n = j;
        return;
    }

    if (arr[i] % 2 == 0) {
        arr[j++] = arr[i];
    }
    removeOdd(arr, n, i + 1, j);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    removeOdd(arr, n, 0, 0);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}