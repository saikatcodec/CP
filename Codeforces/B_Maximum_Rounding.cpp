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
        string num;
        cin >> num;

        int ind = -1;
        for (int i = num.size() - 1; i > 0; i--) {
            if (num[i] >= '5') {
                num[i - 1] += 1;
                num[i] = '0';
                ind = i - 1;
            }
        }

        if (ind != -1) {
            for (int i = ind + 1; i < num.size(); i++) {
                num[i] = '0';
            }
        }

        if (num[0] >= '5') {
            cout << 1;
            for (int i = 0; i < num.size(); i++) {
                cout << 0;
            }
            cout << nl;
        } else {
            cout << num << nl;
        }
    }

    return 0;
}