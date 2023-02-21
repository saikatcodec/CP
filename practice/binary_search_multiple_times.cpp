#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void helper(int arr[], int st, int last, int key, vector<int> &ans) {
    if (st > last) {
        return;
    }

    while (st <= last) {
        int mid = (st + last) / 2;
        if (arr[mid] == key) {
            ans.push_back(mid);
            helper(arr, st, mid - 1, key, ans);    // left side call
            helper(arr, mid + 1, last, key, ans);  // right side call
            return;
        } else if (arr[mid] > key) {
            last = mid - 1;
        } else {
            st = mid + 1;
        }
    }
}

vector<int> binary_search(int arr[], int n, int key) {
    vector<int> ans;
    int st = 0;
    int last = n - 1;
    helper(arr, st, last, key, ans);

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

    vector<int> index;
    index = binary_search(arr, n, key);
    if (!index.empty()) {
        sort(index.begin(), index.end());
        cout << "Element founds at ";
        for (auto ele : index) {
            cout << ele << " ";
        }

        cout << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}