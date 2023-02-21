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

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    int n;
    cin >> n;

    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] - b[i];
    }
    
    pbds st;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (st.size() - st.order_of_key({-c[i], n + 1}));
        st.insert({c[i], i});
    }
    
    cout << ans << nl;
    

    return 0;
}