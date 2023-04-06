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

    string s, t;
    cin >> s >> t;

    int x = 0;
    for (auto ele : s) {
        if (ele >= '0' && ele <= '9') {
            x += (ele - '0');
        }
    }

    int y = 0;
    for (auto ele : t) {
        if (ele >= '0' && ele <= '9') {
            y += (ele - '0');
        }
    }

    int arr[3];
    arr[0] = x + y;
    arr[1] = abs(x - y);
    arr[2] = x * y;

    sort(arr, arr + 3);
    cout << "\"" << arr[1] << "\"" << nl;

    return 0;
}