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

bool check(ll arr[], int n, ll mid) {
    int l = 0, cnt = 0;
    for (int r = l + 1; r < n; r++) {
        if (arr[l] + mid + mid < arr[r]) {
            cnt++;
            l = r;
        }
    }
    cnt++;
    if (cnt > 3) {
        return false;
    } else {
        return true;
    }
}

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll l = 0, r = 1e10, ans = 0;
        while (l < r) {
            ll mid = (l + r) >> 1;

            if (check(arr, n, mid)) {
                ans = mid;
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << nl;
    }

    return 0;
}