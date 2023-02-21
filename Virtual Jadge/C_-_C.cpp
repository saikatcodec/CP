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

    int t, q;
    cin >> t;
    cin.ignore();
    q = t;

    while (t--) {
        string name, hidden;
        getline(cin, name);
        getline(cin, hidden);

        transform(name.begin(), name.end(), name.begin(), ::tolower);
        transform(hidden.begin(), hidden.end(), hidden.begin(), ::tolower);

        sort(name.begin(), name.end());
        sort(hidden.begin(), hidden.end());
        name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());
        hidden.erase(remove_if(hidden.begin(), hidden.end(), ::isspace), hidden.end());

        if (name == hidden) {
            cout << "Case " << (q - t) << ": "
                 << "Yes" << nl;
        } else {
            cout << "Case " << (q - t) << ": "
                 << "No" << nl;
        }
    }

    return 0;
}