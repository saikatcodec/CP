#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

int cntThree(ll n) {
    int cnt = 0;

    while (n % 3 == 0) {
        cnt++;
        n /= 3;
    }

    return cnt;
}

int main() {
    FIO;

    int n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
        v[i].first = -cntThree(v[i].second);
    }

    sort(v.begin(), v.end());

    for (auto x : v) {
        cout << x.second << " ";
    }
    cout << nl;

    return 0;
}