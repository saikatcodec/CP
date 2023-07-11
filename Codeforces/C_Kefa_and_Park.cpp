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

map<int, list<int>> tr;
int cnt = 0;

void dfs(int cats[], int src, int prnt, int prevC, int m) {
    int nC = 0;
    if (cats[src] == 1) {
        nC = cats[src] + prevC;
    } else {
        nC = 0;
    }
    if (nC > m) {
        return;
    }

    auto ad = tr[src];
    if (ad.size() == 1 && *(ad.begin()) == prnt) {
        cnt++;
        return;
    }

    for (auto ele : ad) {
        if (ele != prnt) {
            dfs(cats, ele, src, nC, m);
        }
    }
}

int main() {
    FIO;

    int n, m;
    cin >> n >> m;

    int cats[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> cats[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    dfs(cats, 1, 0, 0, m);
    cout << cnt << nl;

    return 0;
}