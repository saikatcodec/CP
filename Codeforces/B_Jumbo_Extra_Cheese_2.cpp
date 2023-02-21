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
        ll n, ans = 0;
        cin >> n;

        vector<pair<ll, ll>> vp;
        for (ll i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;

            if (a > b) {
                swap(a, b);
            }
            vp.push_back({b, a});
        }

        if (n == 1) {
            ans = 2 * (vp[0].first + vp[0].second);
        }
        else {
            sort(vp.begin(), vp.end());

            ll a[n], b[n];
            ll i = 0, j = n - 1, k = 0;
            while (i <= j) {
                a[i] = vp[k].second;
                b[i] = vp[k].first;
                i++, k++;

                if (i <= j) {
                    a[j] = vp[k].second;
                    b[j] = vp[k].first;
                    j--, k++;
                }
            }

            for (ll i = 0; i < n; i++) {
                if (i == 0) {
                    ans += ((2 * a[i]) + b[i]);
                }
                else if (i == n - 1) {
                    ans += ((2 * a[i]) + abs(b[i] - b[i - 1]) + b[i]);
                }
                else {
                    ans += ((2 * a[i]) + abs(b[i] - b[i - 1]));
                }
            }
        }

        cout << ans << nl;
    }

    return 0;
}