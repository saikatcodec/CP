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
        ll n;
        cin >> n;

        vector<ll> fac;
        for (int i = 1; i <= 100; i++) {
            if (n % i == 0) {
                fac.push_back(i * 1LL);
                ll tmp = n / i;
                fac.push_back(tmp);
            }
        }

        ll cnt, tmp = cnt = 1;
        sort(fac.begin(), fac.end());
        for (int i = 0; i < fac.size(); i++) {
            if ((i != fac.size() - 1) and (fac[i] + 1 == fac[i + 1])) {
                tmp++;
            } else {
                cnt = max(cnt, tmp);
                tmp = 1;
            }
        }

        cout << cnt << nl;
    }

    return 0;
}