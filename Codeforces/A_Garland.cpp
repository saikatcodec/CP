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
        string n;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n.size(); i++) {
            mp[n[i]]++;
        }

        bool flag = true;
        for (auto it : mp) {
            if (it.second == 4) {
                cout << -1 << nl;
                flag = false;
                break;
            } else if (it.second == 3) {
                cout << 6 << nl;
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << 4 << nl;
        }
    }

    return 0;
}