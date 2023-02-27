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

int rengeValue(int arr[], int left, int right, int l, int r) {
    if (left == right) {
        if (arr[left] <= r and arr[left] >= l) {
            return 1;
        } else {
            return 0;
        }
    }

    int mid = (left + right) / 2;

    return rengeValue(arr, left, mid, l, r) + rengeValue(arr, mid + 1, right, l, r);
}

int main() {
    FIO;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int ans = rengeValue(arr, 0, n - 1, l, r);
        cout << ans << " ";
    }
    cout << nl;

    return 0;
}