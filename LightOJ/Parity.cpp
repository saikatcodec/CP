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
        int n;
        cin >> n;

        int noBits = floor(log2(n)) + 1; // Determine the length of binary digit

        int noOne = 0;
        for (int i = 0; i < noBits; i++) {
            if (n & 1) { // If last digit of number is set(1)
                noOne++;
            }
            n >>= 1; // Right shift the number
        }

        if (noOne & 1) {
            cout << "Case " << ++c << ": odd" << nl;
        } else {
            cout << "Case " << ++c << ": even" << nl;
        }
    }

    return 0;
}