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
        ll n, q;
        cin >> n >> q;

        ll arr[n], sum = 0, odd = 0, even = 0; 
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] % 2 == 0) {
                even++;
            }
        }

        odd = n - even;

        for (ll i = 0; i < q; i++) {
            ll j, aj;
            cin >> j >> aj;

            if (j == 0) {
                sum += (even * aj);
                if (aj & 1) {
                    even += (even * -1);
                    odd = n - even;
                }
            }
            else if (j == 1) {
                sum += (odd * aj);
                if (aj & 1) {
                    odd += (odd * -1);
                    even = n - odd;
                }
            }

            cout << sum << nl;
        }
    }

    return 0;
}