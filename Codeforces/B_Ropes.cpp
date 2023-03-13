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

bool pieces(int n, int arr[], double len, int k) {
    if (len <= 0) {
        return true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += floor(arr[i] / len);
    }

    return (ans >= k) ? true : false;
}

int main() {
    FIO;

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double l = 0.0, r = 1e8;
    cout << setprecision(7);
    while (r - l > 1e-6) {
        double mid = l + (r - l) / 2.0;

        if (pieces(n, arr, mid, k)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << nl;

    return 0;
}