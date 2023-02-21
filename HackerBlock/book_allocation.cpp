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

bool check(int arr[], int n, int mid, int st) {
    int sCnt = 1, sum = arr[0];
    for (int i = 1; i < n; i++) {
        sum += arr[i];
        if (sum > mid) {
            sCnt++;
            sum = arr[i];
        }
    }

    if (sCnt == st) {
        return true;
    } else {
        return false;
    }
}

int main() {
    FIO;

    testCase(t) {
        int n, m;
        cin >> n >> m;

        int arr[n], sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        int low = 0, high = sum;
        while (low < high) {
            int mid = (low + high) / 2;

            bool flag = check(arr, n, mid, m);

            if (flag) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << high << nl;
    }

    return 0;
}