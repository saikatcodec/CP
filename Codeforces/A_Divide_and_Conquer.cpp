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
// clang-format on
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    testCase(t) {
        ll n;
        cin >> n;

        ll arr[n];
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        if (!(sum & 1)) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            ll x = sum - arr[i];
            ll cnt = 0;
            if ((x % 2) && (arr[i] % 2 == 0)) {
                while (arr[i] >= 1) {
                    arr[i] /= 2;
                    cnt++;
                    if (arr[i] % 2)
                        break;
                }
            } else if ((x % 2 == 0) && (arr[i] % 2)) {
                while (arr[i] >= 1) {
                    arr[i] /= 2;
                    cnt++;
                    if (arr[i] % 2 == 0)
                        break;
                }
            }
            ans = min(ans, cnt);
        }

        cout << ans << nl;
    }

    return 0;
}