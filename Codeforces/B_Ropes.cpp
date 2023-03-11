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

int pieces(int n, int arr[], float len) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += floor(arr[i] / len);
    }

    return ans;
}

int main() {
    FIO;

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    float l = 0.0, r = INT_MAX * 1.0;
    float ans = 0.0;
    while (r - l > 0.000001) {
        float mid = (l + r) * 0.5;
        cerr << mid << nl;

        if (pieces(n, arr, mid) >= k) {
            l = mid;
            ans = mid;
        } else {
            r = mid;
        }
    }

    cout << l << nl;

    return 0;
}