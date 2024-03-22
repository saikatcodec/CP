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

    int nc;
    cin >> nc;

    vector<vector<int>> cals;
    int totMnt[nc];
    for (int i = 0; i < nc; i++) {
        int p;
        cin >> p;

        vector<int> mnts(p);
        int tot = 0;
        for (int j = 0; j < p; j++) {
            cin >> mnts[j];
            tot += mnts[j];
        }
        cals.push_back(mnts);
        totMnt[i] = tot;
    }

    int q;
    cin >> q;

    int c = 0;
    while (q--) {
        int cal1, cal2, d, m, y;
        cin >> cal1 >> cal2 >> d >> m >> y;

        int tot = totMnt[cal1 - 1] * (y - 1);
        for (int i = 0; i < m - 1; i++) {
            tot += cals[cal1 - 1][i];
        }
        tot += d;

        int ny = tot / totMnt[cal2 - 1];
        int remDay = tot - (ny * totMnt[cal2 - 1]);
        if (remDay == 0) {
            cout << "Query " << ++c << ": "
                 << cals[cal2 - 1][cals[cal2 - 1].size() - 1] << " "
                 << cals[cal2 - 1].size() << " " << ny << nl;
        } else {
            ny++;
            int mn = 0;
            for (int i = 0; i < cals[cal2 - 1].size(); i++) {
                if (remDay <= cals[cal2 - 1][i]) {
                    mn = i + 1;
                    break;
                } else {
                    remDay -= cals[cal2 - 1][i];
                }
            }

            cout << "Query " << ++c << ": " << remDay << " " << mn << " " << ny
                 << nl;
        }
    }

    return 0;
}