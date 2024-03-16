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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (is_sorted(arr, arr + n)) {
            cout << "YES" << nl;
        } else {
            vector<int> a;
            a.push_back(arr[n - 1]);
            bool flag = false;
            for (int i = n - 2; i >= 0; i--) {
                if ((arr[i] <= arr[i + 1]) && !flag) {
                    a.push_back(arr[i]);
                } else {
                    if (arr[i] < 10) {
                        a.push_back(arr[i]);
                    } else {
                        a.push_back(arr[i] % 10);
                        a.push_back(arr[i] / 10);
                        flag = true;
                    }
                }
            }

            if (is_sorted(a.begin(), a.end(), greater<int>())) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }

    return 0;
}