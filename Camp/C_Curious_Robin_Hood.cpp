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
void build(int arr[], int s, int e, int ind) {
    if (s == e) {
        tr[ind] = arr[s];
        return;
    }

    int m = (s + e) >> 1;
    build(arr, s, m, 2 * ind);
    build(arr, m + 1, e, 2 * ind + 1);
    tr[ind] = tr[2 * ind] + tr[2 * ind + 1];
}

void dltVal(int s, int e, int i, int ind) {
    if (i < s || i > e) {
        return;
    }

    if (s == e) {
        cout << tr[ind] << nl;
        tr[ind] = 0;
        return;
    }

    int m = (s + e) >> 1;
    dltVal(s, m, i, 2 * ind);
    dltVal(m + 1, e, i, 2 * ind + 1);
    tr[ind] = tr[2 * ind] + tr[2 * ind + 1];
}

void update(int s, int e, int i, int val, int ind) {
    if (i < s || i > e) {
        return;
    }

    if (s == e) {
        tr[ind] += val;
        return;
    }

    int m = (s + e) >> 1;
    update(s, m, i, val, 2 * ind);
    update(m + 1, e, i, val, 2 * ind + 1);
    tr[ind] = tr[2 * ind] + tr[2 * ind + 1];
}

int querySum(int s, int e, int l, int r, int ind) {
    if (l > e || r < s) {
        return 0;
    }

    if (l <= s && e <= r) {
        return tr[ind];
    }

    int m = (s + e) >> 1;
    int lf = querySum(s, m, l, r, 2 * ind);
    int rt = querySum(m + 1, e, l, r, 2 * ind + 1);
    return lf + rt;
}

int main() {
    FIO;

    int c = 0;
    testCase(t) {
        tr.clear();
        int n, q;
        cin >> n >> q;
        tr.resize(4 * n + 1, 0);

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        build(arr, 0, n - 1, 1);

        cout << "Case " << ++c << ":\n";
        while (q--) {
            int op;
            cin >> op;

            if (op == 1) {  // give all money
                int i;
                cin >> i;
                dltVal(0, n - 1, i, 1);
            } else if (op == 2) {  // add money
                int i, val;
                cin >> i >> val;
                update(0, n - 1, i, val, 1);
            } else if (op == 3) {  // print total money
                int l, r;
                cin >> l >> r;
                cout << querySum(0, n - 1, l, r, 1) << nl;
            }
        }
    }

    return 0;
}