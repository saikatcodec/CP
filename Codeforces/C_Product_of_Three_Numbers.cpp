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

vector<int> primeDivisor(int n) {
    vector<int> div;

    while (n % 2 == 0) {
        div.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            div.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        div.push_back(n);
    }

    return div;
}

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        vector<int> div = primeDivisor(n);
        if (div.size() < 3) {
            cout << "NO" << nl;
        } else {
            vector<int> ans;
            ans.push_back(div[0]);
            ans.push_back(div[1]);

            int s = 0;
            for (int i = 2; i < div.size(); i++) {
                s += div[i];
            }
            ans.push_back(s);

            cout << "YES" << nl;
            for (auto ele : ans) {
                cout << ele << " ";
            }
            cout << nl;
        }
    }

    return 0;
}