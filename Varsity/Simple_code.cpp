#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter element num: ";
    cin >> n;

    int arr[n];
    cout << "Enter element: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int pos = binarySearch(arr, n, key);
    if (pos >= 0) {
        cout << "Element at index " << pos << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}