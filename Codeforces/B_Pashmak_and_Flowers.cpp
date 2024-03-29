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

    ll n;
    cin >> n;

    ll arr[n];
    unordered_map<int, int> freq;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    sort(arr, arr + n);
    int maxDif = arr[n - 1] - arr[0];

    if (arr[0] == arr[n - 1]) {
        cout << maxDif << " " << n * 1LL * (n - 1) / 2 << nl;
    } else {
        cout << maxDif << " " << freq[arr[0]] * 1LL * freq[arr[n - 1]] << nl;
    }

    return 0;
}