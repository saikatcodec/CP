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

vector<int> tr;
void buildTr(int s, int e, int i, int arr[]) {
    if (s == e) {
        tr[i] = arr[s];
        return;
    }

    int mid = (s + e) >> 1;
    buildTr(s, mid, 2 * i, arr);
    buildTr(mid + 1, e, 2 * i + 1, arr);
    tr[i] = min(tr[2 * i], tr[2 * i + 1]);
}

int query(int l, int r, int s, int e, int i) {
    if (r < s || l > e) {
        return INT_MAX;
    }
    if (l <= s && e <= r) {
        return tr[i];
    }

    int mid = (s + e) >> 1;
    return min(query(l, r, s, mid, 2 * i), query(l, r, mid + 1, e, 2 * i + 1));
}

int main() {
    FIO;

    int c = 0;
    testCase(t) {
        int n, q;
        cin >> n >> q;

        tr.clear();
        tr.resize(4 * n, INT_MAX);

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        buildTr(0, n - 1, 1, arr);

        cout << "Case " << ++c << ":\n";
        while (q--) {
            int l, r;
            cin >> l >> r;

            cout << query(l - 1, r - 1, 0, n - 1, 1) << nl;
        }
    }

    return 0;
}