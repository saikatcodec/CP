#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

int main() {
    FIO;

    testCase(t) {
        ll n;
        cin >> n;

        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll ans = 0;
        for (int i = 0; i < n - 2; i++) {
            ll val = abs(arr[i] - arr[i + 1]) + abs(arr[n - 1] - arr[i]);
            ans = max(ans, val);
        }
        for (int i = n - 2; i >= 1; i--) {
            ll val = abs(arr[i] - arr[i + 1]) + abs(arr[0] - arr[i + 1]);
            ans = max(ans, val);
        }

        cout << ans << nl;
    }

    return 0;
}