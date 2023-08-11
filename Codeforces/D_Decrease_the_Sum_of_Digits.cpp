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
        ll n;
        int s;
        cin >> n >> s;

        vector<int> digits;
        ll tmp = n;
        int digitSum = 0;
        while (tmp > 0) {
            digits.push_back(tmp % 10);
            digitSum += tmp % 10;
            tmp /= 10;
        }
        reverse(digits.begin(), digits.end());

        if (digitSum <= s) {
            cout << 0 << nl;
        } else {
            int ptr = -1, sum = 0;
            for (int i = 0; i < digits.size(); i++) {
                sum += digits[i];
                if (sum >= s) {
                    ptr = i;
                    break;
                }
            }

            ll ans = 0;
            int sz = digits.size();

            if (ptr == 0) {
                ans = 1;
                while (sz--) {
                    ans = ans * 10;
                }

                cout << ans - n << nl;
            } else {
                for (int i = 0; i < ptr - 1; i++) {
                    ans = ans * 10 + digits[i];
                }
                ans = ans * 10 + (digits[ptr - 1] + 1);
                sz -= ptr;
                while (sz--) {
                    ans = ans * 10;
                }

                cout << ans - n << nl;
            }
        }
    }

    return 0;
}