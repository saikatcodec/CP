#include <bits/stdc++.h>
using namespace std;

vector<int> tr;
void build(int arr[], int s, int e, int ind) {
    if (s == e) {
        tr[ind] = arr[s];
        return;
    }

    int m = (s + e) >> 1;
    int lf = 2 * ind, rt = 2 * ind + 1;
    build(arr, s, m, lf);
    build(arr, m + 1, e, rt);
    tr[ind] = min(tr[lf], tr[rt]);
}

int query(int s, int e, int l, int r, int ind) {
    if (l <= s && e <= r) {
        return tr[ind];
    }

    if (r < s || e < l) {
        return INT_MAX;
    }

    int m = (s + e) >> 1;
    int lf = query(s, m, l, r, 2 * ind);
    int rt = query(m + 1, e, l, r, 2 * ind + 1);
    return min(lf, rt);
}

void update(int s, int e, int i, int val, int ind) {
    if (s == e) {
        tr[ind] = val;
        return;
    }

    if (i < s || i > e) {
        return;
    }

    int m = (s + e) >> 1;
    update(s, m, i, val, 2 * ind);
    update(m + 1, e, i, val, 2 * ind + 1);
    tr[ind] = min(tr[2 * ind], tr[2 * ind + 1]);
}

int main() {
    int n;
    cin >> n;

    tr.resize(4 * n + 1, INT_MAX);
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(arr, 0, n - 1, 1);
    update(0, n - 1, 2, -10, 1);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << query(0, n - 1, l - 1, r - 1, 1) << endl;
    }

    return 0;
}