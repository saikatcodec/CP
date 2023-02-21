/**
 * Quick sort using recursion
 */
#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[high];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j) {
        quickSort(arr, low, j);
    }
    if (i < high) {
        quickSort(arr, i, high);
    }
}

int main() {
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
