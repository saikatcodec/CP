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

class Graph {
    unordered_map<int, list<int>> g;

    int bfs(int st, unordered_map<int, bool> &vst) {
        queue<int> q;
        unordered_set<int> v, l;

        q.push(st);
        vst[st] = true;
        v.insert(st);

        int ans = 0;

        while (!q.empty()) {
            int fnt = q.front();
            q.pop();

            for (auto ele : g[fnt]) {
                if (!vst[ele]) {
                    q.push(ele);
                    vst[ele] = true;
                }

                if (v.count(fnt) == 1) {
                    l.insert(ele);
                } else if (l.count(fnt) == 1) {
                    v.insert(ele);
                }
            }

            ans = max(v.size(), l.size());
        }

        return ans;
    }

   public:
    void addEg(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int modiBfs(int st) {
        unordered_map<int, bool> vst;
        int sum = 0;
        for (auto node : g) {
            if (!vst[node.first]) {
                sum += bfs(node.first, vst);
            }
        }

        return sum;
    }
};

int main() {
    FIO;

    int t;
    cin >> t;

    int q = 0;
    while (t--) {
        int n;
        cin >> n;

        Graph g;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            g.addEg(a, b);
        }

        int ans = g.modiBfs(1);
        cout << "Case " << ++q << ": " << ans << nl;
    }

    return 0;
}