#include <iostream>
using namespace std;

int first_occurence(int arr[], int n, int key) {
    int st = 0;
    int last = n - 1;

    int ans = -1;

    while (st <= last) {
        int mid = (st + last) / 2;

        if (arr[mid] == key) {
            ans = mid;
            last = mid - 1;
        } else if (arr[mid] > key) {
            last = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int last_occurence(int arr[], int n, int key) {
    int st = 0;
    int last = n - 1;

    int ans = -1;

    while (st <= last) {
        int mid = (st + last) / 2;

        if (arr[mid] == key) {
            ans = mid;
            st = mid + 1;
        } else if (arr[mid] > key) {
            last = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
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

    int index = first_occurence(arr, n, key);
    if (index >= 0) {
        cout << "First occurence element at " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    index = last_occurence(arr, n, key);
    if (index >= 0) {
        cout << "Last occurence element at " << index << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}