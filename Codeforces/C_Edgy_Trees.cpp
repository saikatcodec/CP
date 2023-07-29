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

#define N 100002
vector<vector<int>> adj(N);

ll binExp(ll n, ll k) {
    ll res = 1;
    while (k > 0) {
        if (k & 1) {
            res = ((res % mod) * (n % mod)) % mod;
        }

        n = n * n % mod;
        k >>= 1;
    }

    return res % mod;
}

void dfs_hel(int src, int &n, map<int, bool> &vst) {
    vst[src] = true;
    n++;
    for (auto ele : adj[src]) {
        if (!vst[ele]) {
            dfs_hel(ele, n, vst);
        }
    }
}

void solve(ll n, ll k) {
    map<int, bool> vst;
    vector<ll> tot;

    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            int temp = 0;
            dfs_hel(i, temp, vst);
            tot.push_back(temp * 1LL);
        }
    }

    ll ans = 0;
    for (auto ele : tot) {
        ans = ((ans % mod) + (binExp(ele, k) % mod)) % mod;
    }

    ll nToK = binExp(n, k) % mod;

    cout << (nToK % mod - (ans % mod) + mod) % mod << nl;
}

int main() {
    FIO;

    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c == 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    solve(n, k);

    return 0;
}