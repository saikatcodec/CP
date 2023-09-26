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

vector<int> adj[300002];
vector<int> lev(300002, 0);

void bfs(int src) {
    lev[src] = 0;
    queue<int> q;
    map<int, bool> vst;
    vst[src] = true;
    q.push(src);

    while (!q.empty()) {
        int fnt = q.front();
        q.pop();

        for (auto ele : adj[fnt]) {
            if (!vst[ele]) {
                q.push(ele);
                vst[ele] = true;
                lev[ele] = lev[fnt] + 1;
            }
        }
    }
}

int main() {
    FIO;

    int s, n, e;
    cin >> s >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(n);

    int mx = INT_MIN;
    for (int i = 1; i <= s; i++) {
        mx = max(mx, lev[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= s; i++) {
        if (lev[i] == mx) {
            cnt++;
        }
    }

    cout << cnt << nl;

    return 0;
}