#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define nl "\n"
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
    FIO;

    testCase(t) {
        double a, b;
        cin >> a >> b;

        double area = 0.5 * a * b;
        cout << ps(area, 9) << nl;
    }

    return 0;
}