/**
 * Quick sort without recursion
 */
#include <iostream>
#include <stack>
using namespace std;

void quickSort(int arr[], int low, int high) {
    stack<int> s;
    s.push(low);
    s.push(high);
    while (!s.empty()) {
        int h = s.top();
        s.pop();
        int l = s.top();
        s.pop();

        int i = l, j = h;
        int pivot = arr[(l + h) / 2];

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

        if (l < j) {
            s.push(l);
            s.push(j);
        }
        if (i < h) {
            s.push(i);
            s.push(h);
        }
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
