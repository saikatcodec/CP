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

vector<int> tr, lazy;
void update(int s, int e, int l, int r, int val, int ind) {
    if (lazy[ind] != 0) {
        tr[ind] += (lazy[ind] * (e - s + 1));
        if (s != e) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (l > e || r < s) {
        return;
    }

    if (l <= s && e <= r) {
        tr[ind] += (val * (e - s + 1));
        if (s != e) {
            lazy[2 * ind] += val;
            lazy[2 * ind + 1] += val;
        }
        return;
    }

    int m = (s + e) >> 1;
    update(s, m, l, r, val, 2 * ind);
    update(m + 1, e, l, r, val, 2 * ind + 1);
    tr[ind] = tr[2 * ind] + tr[2 * ind + 1];
}

int query(int s, int e, int l, int r, int ind) {
    if (lazy[ind] != 0) {
        tr[ind] += (lazy[ind] * (e - s + 1));
        if (s != e) {
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (l > e || r < s) {
        return 0;
    }

    if (l <= s && e <= r) {
        return tr[ind];
    }

    int m = (s + e) >> 1;
    int lf = query(s, m, l, r, 2 * ind);
    int rt = query(m + 1, e, l, r, 2 * ind + 1);
    return lf + rt;
}

int32_t main() {
    FIO;

    int c = 0;
    testCase(t) {
        tr.clear();
        lazy.clear();
        int n, q;
        cin >> n >> q;
        tr.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);

        cout << "Case " << ++c << ": " << nl;
        while (q--) {
            int op;
            cin >> op;

            if (op == 0) {  // update
                int l, r, val;
                cin >> l >> r >> val;

                update(0, n - 1, l, r, val, 1);
            } else {  // query
                int l, r;
                cin >> l >> r;

                cout << query(0, n - 1, l, r, 1) << nl;
            }
        }
    }

    return 0;
}