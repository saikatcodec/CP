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

bool check(int n) {
    bool dp[1100] = {0};

    dp[0] = 1;
    for (int i = 1; i < 1100; i++) {
        if (i >= 11 and dp[i - 11]) {
            dp[i] = 1;
        }
        if (i >= 111 and dp[i - 111]) {
            dp[i] = 1;
        }
    }

    return dp[n];
}

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        if (n > 1099 or check(n)) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}