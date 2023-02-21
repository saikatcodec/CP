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

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                int a;
                cin >> a;

                mp[a] += j;
            }
        }

        vector<pair<int, int>> vp;
        for (auto p : mp) {
            vp.push_back({p.first, p.second});
        }

        sort(vp.begin(), vp.end(), [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second < p2.second;
        });

        for (auto p : vp) {
            cout << p.first << " ";
        }
        cout << nl;
    }

    return 0;
}