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
        int arr[4];
        for (int i = 0; i < 4; i++) {
            cin >> arr[i];
        }

        int minIndex = min_element(arr, arr + 4) - arr;
        int maxIndex = max_element(arr, arr + 4) - arr;

        if ((minIndex == 0 and maxIndex == 3) or (maxIndex == 0 and minIndex == 3)) {
            cout << "YES" << nl;
        } else if ((minIndex == 1 and maxIndex == 2) or (maxIndex == 1 and minIndex == 2)) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}