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

    ll n, k;
    cin >> n >> k;

    ll arr[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    ll cnt = 1;
    bool flag = true;
    ll ans;
    for (ll i = 0; i < n - 1; i++) {
        ll dif = arr[i + 1] - arr[i];
        ll ned = dif * cnt;
        cnt++;
        if (ned > k) {
            ans = arr[i];
            flag = false;
            break;
        } else {
            k -= ned;
        }
    }

    if (flag) {
        if (n == 1) {
            ans = arr[n - 1] + k;
        } else {
            ans = arr[n - 1] + k / n;
        }
    }

    cout << ans << nl;

    return 0;
}