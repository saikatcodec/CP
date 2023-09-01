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

vector<int> tr, lz;
void update(int s, int e, int l, int r, int val, int ind) {
    if (lz[ind] != 0) {
        tr[ind] += lz[ind];
        if (s != e) {
            lz[2 * ind] += lz[ind];
            lz[2 * ind + 1] += lz[ind];
        }
        lz[ind] = 0;
    }

    // base case
    if (l > e || r < s) {
        return;
    }

    if (l <= s && e <= r) {
        tr[ind] += val;
        if (s != e) {
            lz[2 * ind] += val;
            lz[2 * ind + 1] += val;
        }
        return;
    }

    int m = (s + e) >> 1;
    update(s, m, l, r, val, 2 * ind);
    update(m + 1, e, l, r, val, 2 * ind + 1);
}

void query(int s, int e, int l, int ind) {
    if (lz[ind] != 0) {
        tr[ind] += lz[ind];
        if (s != e) {
            lz[2 * ind] += lz[ind];
            lz[2 * ind + 1] += lz[ind];
        }
        lz[ind] = 0;
    }

    if (l > e || l < s) {
        return;
    }

    if (s == e) {
        cout << tr[ind] << nl;
        return;
    }

    int m = (s + e) >> 1;
    query(s, m, l, 2 * ind);
    query(m + 1, e, l, 2 * ind + 1);
}

int main() {
    FIO;

    testCase(t) {
        tr.clear();
        lz.clear();
        int n, u;
        cin >> n >> u;

        tr.resize(4 * n + 1, 0);
        lz.resize(4 * n + 1, 0);

        while (u--) {
            int l, r, val;
            cin >> l >> r >> val;

            update(0, n - 1, l, r, val, 1);
        }

        int q;
        cin >> q;

        while (q--) {
            int i;
            cin >> i;
            query(0, n - 1, i, 1);
        }
    }

    return 0;
}