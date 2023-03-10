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

    testCase(t) {
        string str;
        cin >> str;

        string a, b, c;
        a = str.substr(0, 1);
        b = str.substr(1, str.size() - 2);
        c = str.substr(str.size() - 1);
        int aP = 1, cP = 1;

        bool flag = false;
        while ((!flag) or (aP < cP)) {
            if ((a <= b and c <= b) or (b <= a and b <= c)) {
                flag = true;
            } else {
                if (a <= b and c <= b) {
                    cP--;
                    b = str.substr(aP, str.size() - 1 - cP);
                    c = str.substr(str.size() - cP);
                } else if (b <= a and c <= b) {
                    aP++;
                    a = str.substr(0, aP);
                    b = str.substr(aP, str.size() - 1 - cP);
                }
            }
        }

        if (flag) {
            cout << a << " " << b << " " << c << nl;
        } else {
            cout << ":(" << nl;
        }
    }

    return 0;
}