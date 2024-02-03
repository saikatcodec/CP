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

    string str;
    cin >> str;

    string ans = "";
    int i = 0;
    while (i < str.length()) {
        if (str[i] == 'W' && str[i + 1] == 'U' && str[i + 2] == 'B') {
            if (ans.length() > 0 && ans[ans.length() - 1] != ' ') {
                ans.push_back(' ');
            }
            i += 3;
            continue;
        }
        ans.push_back(str[i]);
        i++;
    }

    cout << ans << nl;

    return 0;
}