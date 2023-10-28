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

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll sumA = 0, sumB = 0;
        if (k % 2 == 0) {
            for (ll i = 0; i < n; i++) {
                if (arr[i] % 2) {
                    sumA += arr[i];
                    sumB += arr[i];
                } else if (arr[i] % 3 == 0) {
                    sumA += arr[i];
                }
            }
            cout << sumA - sumB << nl;
        } else {
            for (ll i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    sumA += arr[i];
                    sumB += arr[i];
                }
            }
            cout << sumA - sumB << nl;
        }
    }

    return 0;
}