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

        bool flag = is_sorted(arr, arr + n);
        if (flag) {
            cout << 0 << nl;
        } else {
            int ans = 0;
            while (true) {
                if (ans % 2 == 0) {
                    for (int i = 0; i < n - 2; i++) {
                        if (arr[i] > arr[i + 1]) {
                            swap(arr[i], arr[i + 1]);
                            i++;
                        }
                    }
                } else {
                    for (int i = 0; i < n - 1; i++) {
                        if (arr[i] > arr[i + 1]) {
                            swap(arr[i], arr[i + 1]);
                            i++;
                        }
                    }
                }

                ans++;
                if (is_sorted(arr, arr + n)) {
                    break;
                }
            }

            cout << ans << nl;
        }

        for (int i = 0; i < n; i++) {
            cerr << arr[i] << " ";
        }
        cerr << nl;
    }

    return 0;
}