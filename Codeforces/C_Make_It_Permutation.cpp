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
        ll n, c, d;
        cin >> n >> c >> d;

        ll arr[n];
        unordered_map<int, int> mp;
        bool cont = true;
        ll contP = 0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
            if (cont && arr[i] == i + 1) {
                contP = i + 1;
            } else {
                cont = false;
            }
        }

        ll minEle = *min_element(arr, arr + n);
        ll maxEle = *max_element(arr, arr + n);
        ll ans = INT_MAX;

        bool all = all_of(mp.begin(), mp.end(), [](pair<int, int> p) {
            return p.second == 1;
        });

        if (all) {
            ll insertAble = maxEle - mp.size();
            ans = min(ans, insertAble * d);
        }

        bool flag = true;
        for (ll i = 0; i < contP; i++) {
            if (mp[arr[i]] >= 2) {
                flag = false;
                break;
            }
        }
        if (flag && contP > 0) {
            ans = min(ans, (n - contP) * c);
        }
        ll deleteAble = 0;
        for (auto p : mp) {
            deleteAble += p.second;
        }

        ll now = (minEle - 1) * d + (deleteAble - 1) * c;
        ans = min(ans, now);

        now = 1 * d + deleteAble * c;
        ans = min(ans, now);

        cout << ans << nl;
    }

    return 0;
}