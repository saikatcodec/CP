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

int main() {
    FIO;

    int n, q;
    cin >> n >> q;

    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        pq.push(a);
    }

    int pre[n + 2] = {0};
    while (--q) {
        int l, r;
        cin >> l >> r;

        pre[l] += 1;
        pre[r + 1] -= 1;
    }

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i] + pre[i - 1];
    }

    for (auto ele : pre) {
        cout << ele << " ";
    }

    return 0;
}