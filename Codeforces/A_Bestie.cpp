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

int arrGcd(int arr[], int n) {
    int ans = __gcd(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        ans = __gcd(ans, arr[i]);
    }

    return ans;
}

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        int arr[n], ans = 0, fans = 0;
        for (int i = 0; i < n; i++) 
            cin >> arr[i];

        int tempArr[n];
        copy(arr, arr + n, tempArr);

        if (n == 1) {
            if (arr[0] == 1) {
                ans = 0;
                fans = 0;
            }
            else {
                ans = 1;
                fans = 1;
            }
        } 
        else if (arrGcd(arr, n) == 1) {
            ans = 0;
            fans = 0;
        }
        else {
            for (int i = n - 1; i >= 0; i--) {
                arr[i] = __gcd(arr[i], i + 1);
                ans += (n - i);

                if (arrGcd(arr, n) == 1) {
                    break;
                } 
            }

            for (int i = n - 1; i >= 0; i--) {
                int temp = tempArr[i];
                tempArr[i] = __gcd(tempArr[i], i + 1);
                fans += (n - i);

                if (arrGcd(tempArr, n) == 1) {
                    break;
                }
                tempArr[i] = temp;
                fans = 0;
            }
        }

        cout << min(ans, fans) << nl;
    }

    return 0;
}