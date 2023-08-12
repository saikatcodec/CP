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

vector<vector<int>> adj(10005);
vector<int> dp(100005, INT_MAX);

int helper(int src, int val, int &cnt, map<int, bool> &vst) {
    val = min(src, val);
    cnt++;
    vst[src] = true;

    for (auto ele : adj[src]) {
        if (!vst[ele]) {
            val = min(val, helper(ele, val, cnt, vst));
        }
    }

    return val;
}

void dfs(int n, int k) {
    map<int, bool> vst;
    vector<pair<int, int>> minVal;
    vector<int> vals, cnts;

    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            int cnt = 0, val;
            val = helper(i, INT_MAX, cnt, vst);
            minVal.push_back({cnt, val});
        }
    }

    for (auto p : minVal) {
        vals.push_back(p.second);
        cnts.push_back(p.first);
    }

    dp[0] = 0;
    int sum = 0;
    for (int i = 0; i < vals.size(); i++) {
        sum += cnts[i];
        ll minx = min(k, sum);
        for (int j = minx; j > 0; j--) {
            if (j - cnts[i] >= 0) {
                dp[j] = min(dp[j], dp[j - cnts[i]] + vals[i]);
            } else {
                dp[j] = min(dp[j], vals[i]);
            }
        }
    }
    cout << dp[k] << endl;
}

int main() {
    FIO;

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(n, k);

    return 0;
}