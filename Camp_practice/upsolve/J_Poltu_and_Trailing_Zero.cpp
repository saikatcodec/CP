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

ll cal(ll n, ll p) {
    ll x = n / p;
    ll ans = (x * (x - 1) / 2) * p;
    ans += (n - x * p + 1) * x;
    return ans;
}

int main() {
    FIO;

    int q = 0;
    testCase(t) {
        ll n;
        cin >> n;

        ll k = 1, ans = 0;
        for (int i = 1; i <= 12; i++) {
            k *= 5;
            ans += cal(n, k);
        }

        cout << "Case " << ++q << ": " << ans << nl;
    }

    return 0;
}