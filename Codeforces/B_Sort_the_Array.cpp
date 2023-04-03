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

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (is_sorted(arr, arr + n)) {
        cout << "yes" << nl;
        cout << "1 1" << nl;
    } else {
        int l = 0, r = n - 1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                l = i;
                break;
            }
        }
        for (int i = l; i < n - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                r = i;
                break;
            }
        }
        
        sort(arr + l, arr + r + 1);
        if (is_sorted(arr, arr + n)) {
            cout << "yes" << nl;
            cout << l + 1 << " " << r + 1 << nl;
        } else {
            cout << "no" << nl;
        }
    }

    return 0;
}