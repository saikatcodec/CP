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

    string str, newPas;
    cin >> str;

    newPas.push_back(str[0] - 32);
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == 's') {
            newPas.push_back('$');
        } else if (str[i] == 'i') {
            newPas.push_back('!');
        } else if (str[i] == 'o') {
            newPas.push_back('(');
            newPas.push_back(')');
        } else {
            newPas.push_back(str[i]);
        }
    }
    newPas.push_back('.');

    cout << newPas << nl;

    return 0;
}