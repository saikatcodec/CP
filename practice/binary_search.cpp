#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int key) {
    int st = 0;
    int last = n - 1;

    while (st <= last) {
        int mid = (st + last) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            last = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the number of element: ";
    cin >> n;

    int arr[n];
    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int index = binary_search(arr, n, key);
    if (index >= 0) {
        cout << "Element founds at " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}