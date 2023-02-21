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

    int n;
    cin >> n;
    int a[n + 1];
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    if (is_sorted(a + 1, a + n + 1)) {
        if ((n - 1) % 2 == 0) {
            for (int i = 1; i <= n - 1; i++)
                cout << 1 << nl;
        } else
            cout << -1 << nl;

        return 0;
    }

    int maxx = n;
    int i;
    vector<int> v;
    bool flag = false;
    for (i = 1; i <= n - 1; i++) {
        while (mp[maxx] == maxx && (maxx > 0)) {
            maxx--;
        }
        if (maxx == 0) {
            flag = true;
            break;
        }
        v.push_back(mp[maxx]);
        int temp1 = a[mp[maxx]];
        int temp2 = a[mp[maxx] + 1];
        swap(a[mp[maxx]], a[mp[maxx] + 1]);
        swap(mp[temp1], mp[temp2]);
    }

    if (flag && ((n - i) % 2 == 0)) {
        if (is_sorted(a + 1, a + n + 1)) {
            for (auto x : v) {
                cout << x << '\n';
            }
            for (int j = 1; j <= (n - 1 - v.size()); j++) {
                cout << v[v.size() - 1] << nl;
            }
        } else {
            cout << -1 << nl;
        }
    } else if ((flag == false) && (is_sorted(a + 1, a + n + 1))) {
        for (auto x : v) {
            cout << x << '\n';
        }
    } else
        cout << -1 << '\n';

    return 0;
}