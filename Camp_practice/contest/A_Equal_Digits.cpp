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

    int num;
    cin >> num;

    string n = "";
    while (num) {
        n.push_back((num % 10) + '0');
        num /= 10;
    }
    reverse(n.begin(), n.end());

    int ans = n[0] - '0';
    bool flag = false;
    if (n[0] < n[1]) {
        ans++;
    } else if (n[0] == n[1]) {
        for (int i = 2; i < n.size(); i++) {
            if (n[0] < n[i]) {
                ans++;
                break;
            }
        }
    }

    int out = 0;

    for (int i = 0; i < n.size(); i++) {
        out = out * 10 + ans;
    }

    cout << out << nl;

    return 0;
}