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

    set<ll> st;
    st.insert(1);

    auto it = st.begin();

    for (int i = 0; i < 1500; i++) {
        ll num = *it;

                st.insert(num * 2);
        st.insert(num * 3);
        st.insert(num * 5);
        it++;
    }

    it = st.begin();
    for (int i = 2; i <= 1500; i++) {
        it++;
    }

    ll ans = *it;

    cout << "The 1500'th ugly number is " << ans << "." << nl;

    return 0;
}