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

    int arr[n];
    int pos = 0, zero = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] > 0)
            pos++;
        else if (arr[i] < 0)
            neg++;
        else
            zero++;
    }

    float posR = pos * 1.0 / n;
    float negR = neg * 1.0 / n;
    float zeroR = zero * 1.0 / n;

    cout << ps(posR, 6) << nl;
    cout << ps(negR, 6) << nl;
    cout << ps(zeroR, 6) << nl;

    return 0;
}