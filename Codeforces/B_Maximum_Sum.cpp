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

ll maxSum(int n, ll pre[], ll arr[], int i, int k, ll total) {
    if (k == 0) {
        return total;
    }

    ll ans = 0;
    ans = max(maxSum(n - 1, pre, arr, i + 2, k - 1, pre[n] - pre[i]), maxSum(n - 1, pre, arr, i, k - 1, total - arr[n - 1]));

    return ans;
}

int main() {
    FIO;

    testCase(t) {
        int n, k;
        cin >> n >> k;

        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll pre[n + 1] = {0};
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + arr[i];
        }

        ll ans = 0;
        ans = maxSum(n, pre, arr, 2, k, pre[n]);
        cout << ans << nl;
    }

    return 0;
}