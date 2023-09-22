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
        string str;
        cin >> str;

        vector<int> posB;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'B') {
                posB.push_back(i);
            }
        }

        int ans = 0, prev = -1;
        bool ocu = false;
        if (!posB.empty()) {
            for (int i = 0; i < posB.size() - 1; i++) {
                int l = posB[i] - prev - 1;
                prev = posB[i];
                int r = posB[i + 1] - prev - 1;

                if (l >= r and !ocu) {
                    ans += l;
                } else {
                    ans += r;
                    ocu = true;
                }
            }

            if (ocu) {
                ans += (str.size() - *(posB.rbegin()) - 1);
            } else {
                int mx = max((*(posB.rbegin()) - prev - 1), ((int)str.size() - *(posB.rbegin()) - 1));
                ans += mx;
            }
        }

        cout << ans << nl;
    }

    return 0;
}