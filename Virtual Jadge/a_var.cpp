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

    string str;
    while (cin >> str) {
        if (str == "#") {
            break;
        }

        vector<char> small, capital, num;
        for (auto ch : str) {
            if (ch >= 'a' && ch <= 'z') {
                small.push_back(ch);
            } else if (ch >= 'A' && ch <= 'Z') {
                capital.push_back(ch);
            } else {
                num.push_back(ch);
            }
        }

        sort(small.begin(), small.end());
        sort(capital.begin(), capital.end());
        sort(num.begin(), num.end());

        for (auto ch : small) {
            cout << ch;
        }
        for (auto ch : capital) {
            cout << ch;
        }
        for (auto ch : num) {
            cout << ch;
        }
        cout << nl;
    }

    return 0;
}