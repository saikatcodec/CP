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

    testCase(t) {
        int n;
        cin >> n;

        vector<int> digits;
        int tmp = n;
        while (tmp > 0) {
            int d = tmp % 10;
            digits.push_back(d);
            tmp /= 10;
        }

        vector<int> ans;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] > 0) {
                int p = pow(10, i);
                ans.push_back(p * digits[i]);
            }
        }

        cout << ans.size() << nl;
        for (int a : ans) {
            cout << a << " ";
        }
        cout << nl;
    }

    return 0;
}