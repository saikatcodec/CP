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
    int fre[5] = {0};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        fre[arr[i]]++;
    }

    int ans = 0;
    ans = fre[4];
    fre[2] *= 2;

    if (fre[3] >= fre[1]) {
        ans += fre[3];
        fre[1] = 0;
    } else {
        ans += fre[3];
        fre[2] += fre[1] - fre[3];
    }

    ans += ceil(fre[2] * 1.0 / 4);

    cout << ans << nl;

    return 0;
}