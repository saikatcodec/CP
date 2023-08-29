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


int dp[6];

int mP(int p[], int i, int val, int n) {
    if (i >= n) {
        return 0;
    }
    if (val == INT_MAX) {
        val = p[i - 1];
    }

    int pr = max(mP(p, i + 3, INT_MAX, n), mP(p, i + 1, min(val, p[i]), n));
    pr += (p[i] - val);
    dp[i] = pr;
    return pr;
}

int main() {
    FIO;

    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << mP(p, 1, p[0], n) << nl;
    for (auto el : dp) {
        cout << el << " ";
    }

    return 0;
}