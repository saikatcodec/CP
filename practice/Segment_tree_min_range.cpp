#include <bits/stdc++.h>
using namespace std;

vector<int> tr;
void buildTree(int arr[], int l, int r, int index) {
    if (l == r) {
        tr[index] = arr[l];
        return;
    }

    int mid = (l + r) >> 1;
    buildTree(arr, l, mid, 2 * index);
    buildTree(arr, mid + 1, r, 2 * index + 1);
    tr[index] = min(tr[2 * index], tr[2 * index + 1]);
}

int quary(int l, int r, int s, int e, int index) {
    // Complete overlap
    if (s >= l && e <= r) {
        return tr[index];
    }

    // No overlap
    if (r < s || l > e) {
        return INT_MAX;
    }

    // partial overlap
    int mid = (s + e) >> 1;
    int lt = quary(l, r, s, mid, 2 * index);
    int rt = quary(l, r, mid + 1, e, 2 * index + 1);
    return min(lt, rt);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    tr.resize(4 * n + 1, INT_MAX);
    buildTree(arr, 0, n - 1, 1);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << quary(l - 1, r - 1, 0, n - 1, 1) << endl;
    }

    return 0;
}