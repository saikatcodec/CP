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

ll binPow(ll n, ll k, ll m) {
    if (k == 0) {
        return 1;
    }

    n %= m;
    ll ans = binPow(n, k / 2, m) % m;

    if (k & 1) {
        return ((((ans % m) * ans) % m) * n) % m;
    }

    return ((ans % m) * ans) % m;
}

int main() {
    FIO;

    testCase(t) {
        ll n, k;
        cin >> n >> k;

        // To calculate the few first digit of n^k;
        double p = k * log10(n * 1.0);
        int f = pow(10, p - floor(p)) * 100;

        cout << f << "...";
        cout << setw(3) << setfill('0') << binPow(n, k, 1000) << nl;
    }

    return 0;
}