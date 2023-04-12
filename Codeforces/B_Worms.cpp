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

int main() {
    FIO;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> vp(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        vp[i] = {s + 1, s + arr[i]};
        s += arr[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int a;
        cin >> a;

        int l = 0, r = n - 1;
        int ans;
        while (l <= r) {
            int mid = (r + l) / 2;

            if (a >= vp[mid].first && a <= vp[mid].second) {
                ans = mid + 1;
                break;
            } else if (a < vp[mid].first) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << nl;
    }

    return 0;
}