#include <iostream>
using namespace std;

int find_key(int arr[], int n, int key) {
    int st = 0;
    int last = n - 1;

    while (st <= last) {
        int mid = (st + last) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[st] <= arr[mid]) {
            if (arr[mid] >= key and arr[st] <= key) {
                last = mid - 1;
            } else {
                st = mid + 1;
            }
        } else {
            if (arr[mid] <= key and arr[last] >= key) {
                st = mid + 1;
            } else {
                last = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << find_key(arr, n, key) << endl;

    return 0;
}