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

vector<int> parent(100005, -1);
struct dsu {
    void init() {
        parent.clear();
        parent.resize(100005, -1);
    }

    int find(int a) {
        if (parent[a] == -1) {
            return a;
        }

        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            parent[a] = b;
        }
    }
};

int32_t main() {
    FIO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n, q;
        cin >> n >> q;

        int arr[n + 100] = {0};
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        dsu ds;
        ds.init();

        vector<int> ans;
        while (q--) {
            int s;
            cin >> s;

            if (s == 1) {
                int l, r;
                cin >> l >> r;

                ds.unite(l, r);
            } else {
                int id;
                cin >> id;

                int ele = ds.find(arr[id - 1]);
                ans.push_back(ele);
            }
        }

        if (!ans.empty()) {
            cout << "Case " << i << ":" << nl;
            for (auto ele : ans) {
                cout << ele << nl;
            }
        }
    }

    return 0;
}