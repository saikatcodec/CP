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

#define N 500000
vector<int> dvsr[N + 1];
void getDvsr() {
    for (int i = 1; i <= N; i++) {
        vector<int> dv;
        for (int j = 1; j * j <= N; j++) {
            if (i % j == 0) {
                dv.push_back(j);
                dv.push_back(i / j);
            }
        }

        sort(dv.begin(), dv.end());
        dvsr[i] = dv;
    }
}

int main() {
    FIO;
    getDvsr();

    testCase(t) {
        int a, b, m1, m2;
        cin >> a >> b >> m1 >> m2;

        int com = __gcd(a - m1, b - m2);
        if (m1 == 0 && m2 == 0) {
            cout << 1 << nl;
        } else if (a == m1 && b == m2) {
            cout << max(a, b) + 1 << nl;
        } else if (com <= max(m1, m2)) {
            cout << -1 << nl;
        } else {
            int ans = *upper_bound(dvsr[com].begin(), dvsr[com].end(), max(m1, m2));
            cout << ans << nl;
        }
    }

    return 0;
}