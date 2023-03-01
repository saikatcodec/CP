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

    testCase(t) {
        string str1, str2;
        cin >> str1 >> str2;

        if (str1[0] == str2[0]) {
            cout << "YES" << nl;
            cout << str1[0] << "*" << nl;
        } else if (str1.back() == str2.back()) {
            cout << "YES" << nl;
            cout << "*" << str1.back() << nl;
        } else {
            bool temp = false;
            string pre;
            for (int i = 0; i < str1.size(); i++) {
                pre = str1.substr(i, 2);
                for (int j = 0; j < str2.size(); j++) {
                    string pres = str2.substr(j, 2);
                    if (pre == pres) {
                        temp = true;
                        break;
                    }
                }

                if (temp) {
                    break;
                }
            }

            if (temp) {
                cout << "YES" << nl;
                cout << "*" << pre << "*" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }

    return 0;
}