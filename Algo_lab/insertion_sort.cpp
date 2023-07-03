#include <bits/stdc++.h>
using namespace std;

void insertSort(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // set the key value
        int j = i - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertSort(n, arr);  // Call function to sort the elements

    cout << "Sorted elements are : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}