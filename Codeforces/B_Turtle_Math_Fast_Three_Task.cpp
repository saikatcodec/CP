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

        int arr[n], sum = 0;
        set<int> st;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            st.insert(arr[i]);
            sum += arr[i];
        }

        if (sum % 3 == 0) {
            cout << 0 << nl;
        } else {
            int ans = 0;
            int cnt = sum / 3;
            while (cnt >= 0) {
                int dif = sum - (cnt * 3);
                if (st.find(dif) != st.end()) {
                    ans++;
                    break;
                }
                cnt--;
            }

            if (ans != 0) {
                cout << ans << nl;
            } else {
                cout << (((sum / 3) + 1) * 3) - sum << nl;
            }
        }
    }

    return 0;
}