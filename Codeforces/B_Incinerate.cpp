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
// clang-format on
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    testCase(t) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            vp[i].first = a;
        }
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            vp[i].second = a;
        }

        sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });

        auto maxe = *max_element(vp.begin(), vp.end(), [](auto p1, auto p2) {
            return p1.first < p2.first;
        });

        int maxEle = maxe.first;

        queue<pair<int, int>> q;
        for (auto p : vp) {
            q.push(p);
        }

        int ans = k;
        while (maxEle - ans > 0 && k > 0 && !q.empty()) {
            if (q.front().first > ans) {
                k -= q.front().second;
                ans += k;
            } else {
                q.pop();
            }
        }

        if (ans >= maxEle) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}