#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define int long long
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// clang-format on

vector<int> tr, lazy;
void build(int arr[], int s, int e, int ind) {
    if (s == e) {
        tr[ind] = arr[s];
        return;
    }

    int m = (s + e) >> 1;
    build(arr, s, m, 2 * ind);
    build(arr, m + 1, e, 2 * ind + 1);
}

void update(int l, int r, int s, int e, int val, int ind) {
    if (lazy[ind] != 0) {
        tr[ind] += lazy[ind];
        if (s != e) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (l > e || r < s) {
        return;
    }
    if (l <= s && e <= r) {
        tr[ind] += val;
        if (s != e) {
            lazy[2 * ind] += val;
            lazy[2 * ind + 1] += val;
        }
        return;
    }

    int m = (s + e) >> 1;
    update(l, r, s, m, val, 2 * ind);
    update(l, r, m + 1, e, val, 2 * ind + 1);
}

void query(int k, int s, int e, int ind) {
    if (lazy[ind] != 0) {
        tr[ind] += lazy[ind];
        if (s != e) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (k > e || k < s) {
        return;
    }
    if (s == e) {
        cout << tr[ind] << nl;
        return;
    }

    int m = (s + e) >> 1;
    query(k, s, m, 2 * ind);
    query(k, m + 1, e, 2 * ind + 1);
}

int32_t main() {
    FIO;

    int n, q;
    cin >> n >> q;

    tr.resize(4 * n + 1, 0);
    lazy.resize(4 * n + 1, 0);
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(arr, 0, n - 1, 1);

    while (q--) {
        int o;
        cin >> o;

        if (o == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            update(l - 1, r - 1, 0, n - 1, v, 1);
        } else {
            int k;
            cin >> k;
            query(k - 1, 0, n - 1, 1);
        }
    }

    return 0;
}