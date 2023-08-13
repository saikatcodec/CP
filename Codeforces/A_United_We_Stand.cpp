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

        int arr[n];
        map<int, int> fre;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            fre[arr[i]]++;
        }

        int i = 0;
        vector<int> a, b;
        for (auto p : fre) {
            if (i >= fre.size() / 2) {
                int sz = p.second;
                for (int j = 0; j < sz; j++) {
                    b.push_back(p.first);
                }
            } else {
                int sz = p.second;
                for (int j = 0; j < sz; j++) {
                    a.push_back(p.first);
                }
            }
            i++;
        }

        vector<int> tmp;
        for (int i = 0; i < b.size(); i++) {
            for (int j = 0; j < a.size(); j++) {
                if (a[j] % b[i] == 0) {
                    tmp.push_back(b[i]);
                    b[i] = -1;
                }
            }
        }

        for (int i = 0; i < tmp.size(); i++) {
            a.push_back(tmp[i]);
        }

        int la = 0, lb = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != -1) {
                la++;
            }
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != -1) {
                lb++;
            }
        }

        if (la == 0 || lb == 0) {
            cout << -1 << nl;
        } else {
            cout << la << " " << lb << nl;
            for (auto ele : a) {
                if (ele != -1)
                    cout << ele << " ";
            }
            cout << nl;

            for (auto ele : b) {
                if (ele != -1)
                    cout << ele << " ";
            }
            cout << nl;
        }
    }

    return 0;
}