#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) 
            cin >> arr[i];

        if (is_sorted(arr, arr + n)) {
            cout << "0" << nl;
            continue;
        }

        int l, r;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                l = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                r = i;
                break;
            }
        }

        int ans = 0;
        while (l < r) {
            if (arr[l] == 1 and arr[r] == 0) {
                arr[r]++;
                arr[l]--;
                ans++;
            }
            else if (arr[l] == 0) {
                l++;
            }
            else if (arr[r] == 1) {
                r--;
            }
        }

        cout << ans << nl;
    }

    return 0;
}