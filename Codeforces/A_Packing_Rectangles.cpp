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

    ll w, h, n;
    cin >> w >> h >> n;

    ll l = 0, r = inf;
    while (l < r) {
        ll mid = l + (r - l) / 2;

        ll a = (mid / w);
        ll b = mid / h;

        ll c = inf;
        if (a != 0) {
            c = n / a;
            if (n % a) {
                c++;
            }
        }
        if (c <= b) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << r << nl;

    return 0;
}