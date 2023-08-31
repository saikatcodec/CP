#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
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

vector<int> tr;
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

int minQ(int arr[], int l, int r, int s, int e, int ind) {
    if (l <= s && e <= r) {
        return tr[ind];
    }
    if (r < s || e < l) {
        return INT_MAX;
    }

    int m = (s + e) >> 1;
    int lf = minQ(arr, l, r, s, m, 2 * ind);
    int rt = minQ(arr, l, r, m + 1, e, 2 * ind + 1);
    return min(lf, rt);
}

int main() {
    FIO;

    int n;
    cin >> n;

    tr.resize(4 * n + 1, INT_MAX);

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(arr, 0, n - 1, 1);

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << minQ(arr, l, r, 0, n - 1, 1) << nl;
    }

    return 0;
}