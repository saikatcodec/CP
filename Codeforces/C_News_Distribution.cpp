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

vector<int> parent(500005, -1);
vector<int> rnk(500005, 1);

int findRoot(int a) {
    if (parent[a] == -1) {
        return a;
    }

    return parent[a] = findRoot(parent[a]);
}

void unite(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a != b) {
        if (rnk[a] < rnk[b]) {
            swap(a, b);
        }

        parent[a] = b;
        rnk[b] += rnk[a];
    }
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    while (m--) {
        int k;
        cin >> k;

        int arr[k];
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < k - 1; i++) {
            unite(arr[i], arr[i + 1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        int prnt = findRoot(i);
        cout << rnk[prnt] << " ";
    }
    cout << nl;

    return 0;
}