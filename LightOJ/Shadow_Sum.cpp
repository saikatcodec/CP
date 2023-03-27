#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// clang-format on

int main() {
    FIO;

    int c = 0;
    testCase(t) {
        bool used[20005] = {false};
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int shadowSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!used[abs(arr[i])]) { // Used or not
                shadowSum += arr[i];
                used[abs(arr[i])] = true; // Marked as use
            }
        }

        cout << "Case " << ++c << ": " << shadowSum << nl;
    }

    return 0;
}