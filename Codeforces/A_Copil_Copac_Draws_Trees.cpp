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

map<int, list<pair<int, int>>> tr;
int ans;

void dfs(int src, int cnt, int prev, int parnt) {
    ans = max(cnt, ans);
    for (auto u : tr[src]) {
        if (u.first != parnt) {
            int tmp = cnt + (u.second < prev);
            dfs(u.first, tmp, u.second, u.first);
        }
    }
}

int main() {
    FIO;

    testCase(t) {
        tr.clear();
        int n;
        cin >> n;

        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;

            tr[a].push_back({b, i});
            tr[b].push_back({a, i});
        }

        ans = 0;
        dfs(1, 1, 0, -1);
        cout << ans << nl;
    }

    return 0;
}