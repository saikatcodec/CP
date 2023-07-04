#include <bits/stdc++.h>
using namespace std;

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n) {
    // loop to access each array element
    for (int i = 0; i < n - 1; i++) {
        // loop to compare array elements
        for (int j = 0; j < n - i - 1; j++) {
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    bubbleSort(arr, n);  // Call function to sort the elements

    cout << "Sorted elements are : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}