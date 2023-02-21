#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define int long long
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

void solve(int dd, int mm, int yy, vector<int> mp1, int totalDay1, int totalDay2, int p2, vector<int> mp2, int cnt) {
    int total = 0;
    for (int i = 0; i < mm - 1; i++) {
        total += mp1[i];
    }

    total += (dd + ((yy - 1) * totalDay1));

    int year = ceil(total * 1.0 / totalDay2);
    int remaining = total - (totalDay2 * (year - 1));

    int month = 0;
    for (int i = 0; i < p2; i++) {
        if (remaining > mp2[i]) {
            remaining -= mp2[i];
            month = i + 1;
        } else {
            break;
        }
    }
    month++;

    cout << "Query " << cnt << ": ";
    cout << remaining << " " << month << " " << year << nl;
}

int32_t main() {
    FIO;

    int nc;
    cin >> nc;

    vector<vector<int>> cal(nc);
    vector<int> sum(nc);
    for (int i = 0; i < nc; i++) {
        int p;
        cin >> p;
        int total = 0;
        cal[i].resize(p);
        for (int j = 0; j < p; j++) {
            int a;
            cin >> a;
            cal[i][j] = a;
            total += a;
        }

        sum[i] = total;
    }

    int q;
    cin >> q;

    for (int i = 1; i <= q; i++) {
        int cal1, cal2, dd, mm, yy;
        cin >> cal1 >> cal2 >> dd >> mm >> yy;

        solve(dd, mm, yy, cal[cal1 - 1], sum[cal1 - 1], sum[cal2 - 1], cal[cal2 - 1].size(), cal[cal2 - 1], i);
    }

    return 0;
}