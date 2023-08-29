#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    // Array compressed
    int i = 0, j = 0;
    while (i < n) {
        j = i;

        while ((j + 1 < n) && (arr[j + 1] == arr[j] + 1)) {
            j++;
        }

        if (i == j) {
            cout << arr[i] << " ";
            i++;
        } else {
            cout << arr[i] << "-" << arr[j] << " ";
            i = j + 1;
        }
    }

    return 0;
}