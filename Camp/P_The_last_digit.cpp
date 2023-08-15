#include <bits/stdc++.h>

using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// clang-format on

int findLast(int a, int b) {
    int ans = 1;

    while (b > 0) {
        if (b & 1) {
            ans = (ans % 10 * a % 10) % 10;
        }

        b >>= 1;
        a = (a % 10 * a % 10) % 10;
    }

    return ans % 10;
}

int main() {
    FIO;

    testCase(t) {
        int a, b;
        cin >> a >> b;

        cout << findLast(a, b) << nl;
    }

    return 0;
}