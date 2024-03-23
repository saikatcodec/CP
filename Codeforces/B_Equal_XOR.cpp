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
        int n, k;
        cin >> n >> k;
        vector<int> a, b, c, d;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] == a[i + 1])
                i++;
            else {
                c.push_back(a[i]);
            }
        }
        if (a[n - 1] != a[n - 2]) c.push_back(a[n - 1]);
        for (int i = 0; i < a.size() - 1; i++) {
            if (b[i] == b[i + 1])
                i++;
            else {
                d.push_back(b[i]);
            }
        }
        if (b[n - 1] != b[n - 2]) d.push_back(b[n - 1]);
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] == a[i + 1]) {
                c.push_back(a[i]);
                c.push_back(a[i + 1]);
                i++;
            }
        }
        for (int i = 0; i < a.size() - 1; i++) {
            if (b[i] == b[i + 1]) {
                d.push_back(b[i]);
                d.push_back(b[i + 1]);
                i++;
            }
        }
        for (int i = n - 1; i >= n - 2 * k; i--) {
            cout << c[i] << ' ';
        }
        cout << '\n';
        for (int i = n - 1; i >= n - 2 * k; i--) {
            cout << d[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}