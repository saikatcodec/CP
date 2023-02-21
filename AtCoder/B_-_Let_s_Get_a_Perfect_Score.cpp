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
// clang-format on
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    string str[n];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    int ans = 0;

    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (str[k][j] == 'o' || str[i][j] == 'o')
                    cnt++;
            }

            if (cnt == m)
                ans++;
        }
    }

    cout << ans << nl;

    return 0;
}