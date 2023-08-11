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

vector<vector<int>> adj(200005);

void addEdges(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int findDeg(int src, map<int, bool> &vst) {
    int deg = adj[src].size();
    vst[src] = true;

    for (auto ele : adj[src]) {
        if (!vst[ele])
            deg = max(findDeg(ele, vst), deg);
    }

    return deg;
}

bool findCycle(int src, int frst, map<int, bool> &vst) {
    vst[src] = true;

    for (auto ele : adj[src]) {
        if (!vst[ele]) {
            if (findCycle(ele, src, vst)) {
                return true;
            }
        } 
        else if (ele != frst) {
            return true;
        }
    }

    return false;
}

void slove(int n) {
    vector<int> dgs;
    map<int, bool> vst;

    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            int deg = findDeg(i, vst);
            if (deg == 2) {
                dgs.push_back(i);
            }
        }
    }

    int cnt = 0;
    vst.clear();
    for (auto ele : dgs) {
        cnt += findCycle(ele, -1, vst);
    }
    cout << cnt << nl;
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        addEdges(a, b);
    }

    slove(n);

    return 0;
}