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

bool check(ll arr[], ll n, ll val, ll x) {
    ll an = 0;
    for (ll i = 0; i < n; i++) {
        if (val - arr[i] >= 0)
            an += (val - arr[i]);
    }

    if (an > x) {
        return false;
    } else {
        return true;
    }
}

int main() {
    FIO;

    testCase(t) {
        ll n, x;
        cin >> n >> x;

        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll l = 0, r = INT_MAX;
        while (r - l > 1) {
            ll m = (r + l) >> 1;
            if (check(arr, n, m, x)) {
                l = m;
            } else {
                r = m;
            }
        }

        cout << l << nl;
    }

    return 0;
}