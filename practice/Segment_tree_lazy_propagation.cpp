#include <bits/stdc++.h>
using namespace std;

vector<int> tr;
int lazy[10000];

void build(int arr[], int s, int e, int ind) {
    if (s == e) {
        tr[ind] = arr[s];
        return;
    }

    int m = (s + e) >> 1;
    build(arr, s, m, 2 * ind);
    build(arr, m + 1, e, 2 * ind + 1);
    tr[ind] = min(tr[2 * ind], tr[2 * ind + 1]);
}

void update(int s, int e, int l, int r, int val, int ind) {
    // resolve the lazy value
    if (lazy[ind] != 0) {
        tr[ind] += lazy[ind];
        if (s != e) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    // base case - no overlap
    if (r < s || l > e) {
        return;
    }

    // Complete overlap
    if (l <= s && e <= r) {
        tr[ind] += val;
        if (s != e) {
            lazy[2 * ind] += val;
            lazy[2 * ind + 1] += val;
        }
        return;
    }

    int m = (s + e) >> 1;
    update(s, m, l, r, val, 2 * ind);
    update(m + 1, e, l, r, val, 2 * ind + 1);
    tr[ind] = min(tr[2 * ind], tr[2 * ind + 1]);
}

int query(int s, int e, int l, int r, int ind) {
    if (lazy[ind] != 0) {
        tr[ind] += lazy[ind];
        if (s != e) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if (r < s || l > e) {
        return INT_MAX;
    }

    if (l <= s && e <= r) {
        return tr[ind];
    }

    int m = (s + e) >> 1;
    int lf = query(s, m, l, r, 2 * ind);
    int rt = query(m + 1, e, l, r, 2 * ind + 1);
    return min(lf, rt);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    tr.resize(4 * n + 1, INT_MAX);
    build(arr, 0, n - 1, 1);

    cout << "q 1-3: " << query(0, n - 1, 0, 2, 1) << endl;
    cout << "q 3-5: " << query(0, n - 1, 2, 4, 1) << endl;
    cout << "q 5-5: " << query(0, n - 1, 4, 4, 1) << endl;
    update(0, n - 1, 0, 3, 10, 1);
    update(0, n - 1, 2, 4, 5, 1);
    cout << "q 1-3: " << query(0, n - 1, 0, 2, 1) << endl;
    cout << "q 3-5: " << query(0, n - 1, 2, 4, 1) << endl;
    cout << "q 5-5: " << query(0, n - 1, 4, 4, 1) << endl;

    return 0;
}