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

ll getValue(vector<ll> num) {
    ll ans = 0;
    reverse(num.begin(), num.end());
    for (auto ele : num) {
        ans = ans * 10 + ele;
    }

    return ans;
}

int main() {
    FIO;

    testCase(t) {
        ll n;
        cin >> n;

        ll x = 0, y = 0;
        vector<ll> xv, yv;
        bool flag = true;
        while (n) {
            ll temp = n % 10;
            n /= 10;

            ll add = temp / 2;
            ll tempX = add;
            ll tempY = add;

            if (temp & 1) {
                if (flag) {
                    tempX++;
                    flag = false;
                } else {
                    tempY++;
                    flag = true;
                }
            }
            xv.push_back(tempX);
            yv.push_back(tempY);
        }

        x = getValue(xv);
        y = getValue(yv);
        cout << x << " " << y << nl;
    }

    return 0;
}