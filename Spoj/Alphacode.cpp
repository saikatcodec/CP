#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define int long long
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

string str;
vector<int> memo;

int dp(int i) {
    if (i == str.size()) {
        return 1;
    }

    if (memo[i] != -1) return memo[i];

    int ans = 0;
    if (str[i] >= '1' && str[i] <= '9') {
        ans += dp(i + 1);
    }

    if (i + 1 < str.size() && (str[i] == '1')) {
        ans += dp(i + 2);
    }

    if (i + 1 < str.size() && (str[i] == '2' && str[i + 1] <= '6')) {
        ans += dp(i + 2);
    }

    return memo[i] = ans;
}

int32_t main() {
    FIO;

    while (cin >> str && str[0] != '0') {
        memo.clear();
        memo.resize(str.size(), -1);

        cout << dp(0) << nl;
    }

    return 0;
}