#include <bits/stdc++.h>
using namespace std;

int counter_attack(int arr[], int s, int mid, int e) {
    int temp[100000];
    int i = s, j = mid + 1, k = s;
    int cnt = 0;

    while (i <= mid and j <= e) {
        if (arr[i] >= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            cnt += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= e) {
        temp[k++] = arr[j++];
    }

    for (int a = s; a <= e; a++) {
        arr[a] = temp[a];
    }

    return cnt;
}

int inversion_cout(int arr[], int s, int e) {
    if (s >= e) {
        return 0;
    }

    int mid = (e + s) >> 1;
    int left = inversion_cout(arr, s, mid);
    int right = inversion_cout(arr, mid + 1, e);
    int val = counter_attack(arr, s, mid, e);

    return left + right + val;
}

int main() {
    int arr[] = {1, 2, 5, 6, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << inversion_cout(arr, 0, n - 1) << endl;

    return 0;
}