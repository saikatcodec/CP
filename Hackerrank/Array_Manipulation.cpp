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
ll arr[10000002];

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    ll n;
    cin >> n;

    ll size = n + 2;

    testCase(q) {
        ll a, b, k;
        cin >> a >> b >> k;

        arr[a] += k;
        arr[b + 1] -= k;
    }

    for (ll i = 1; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i];
    }

    ll maxEle = *max_element(arr, arr + size);
    cout << maxEle << nl;

    return 0;
}