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

ll tr[800005];
void build(int arr[], int l, int r, int ind) {
    if (l == r) {
        tr[ind] = arr[l];
        return;
    }

    int m = (l + r) >> 1;
    build(arr, l, m, 2 * ind);
    build(arr, m + 1, r, 2 * ind + 1);
    tr[ind] = tr[2 * ind] + tr[2 * ind + 1];
    return;
}

ll query(int l, int r, int s, int e, int ind) {
    if (r < s || l > e) {
        return 0;
    }

    if (l <= s && e <= r) {
        return tr[ind];
    }

    int m = (s + e) >> 1;
    return query(l, r, s, m, 2 * ind) + query(l, r, m + 1, e, 2 * ind + 1);
}

int main() {
    FIO;

    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(arr, 0, n - 1, 1);

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << query(a - 1, b - 1, 0, n - 1, 1) << nl;
    }

    return 0;
}