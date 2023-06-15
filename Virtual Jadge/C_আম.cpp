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

    int n, m;
    cin >> n >> m;

    string ans = "";
    int check = n * 9;
    if (m == 0 && n == 1) {
        cout << 0 << " " << 0 << nl;
    } else if (check < m || m <= 0) {
        cout << -1 << " " << -1 << nl;
        return 0;
    } else {
        int nine = m / 9;
        if (nine <= n) {
            for (int i = 0; i < nine; i++) {
                ans.push_back('9');
            }

            int zer = n - nine;
            if (zer > 0) {
                int rm = m - nine * 9;
                ans.push_back(rm + '0');
            }
            for (int i = 0; i < zer - 1; i++) {
                ans.push_back('0');
            }
        } else {
            cout << -1 << " " << -1 << nl;
            return 0;
        }

        string mAns = ans;
        reverse(mAns.begin(), mAns.end());

        if (mAns[0] == '0' && mAns.size() >= 2) {
            mAns[0] = '1';
            for (int i = 1; i < mAns.size(); i++) {
                if (mAns[i] != '0') {
                    mAns[i] = mAns[i] - 1;
                    break;
                }
            }
        }

        cout << mAns << " " << ans << nl;
    }

    return 0;
}