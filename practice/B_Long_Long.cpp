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

    testCase(t) {
        ll n;
        cin >> n;

        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        bool negP = false, neg = false;
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            if ((arr[i] < 0) || (arr[i] == 0 && negP)) {
                neg = true;
                if (!negP) {
                    negP = true;
                }
            } else {
                neg = false;
            }

            if (neg ^ negP) {
                cnt++;
            }
            negP = neg;
        }

        if ((arr[n - 1] == 0 && negP) || arr[n - 1] < 0) {
            cnt++;
        }

        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            sum += abs(arr[i]);
        }

        cout << sum << " " << cnt << nl;
    }

    return 0;
}