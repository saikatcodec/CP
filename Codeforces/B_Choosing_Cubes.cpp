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

    testCase(t) {
        int n, f, k;
        cin >> n >> f >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int fav = arr[f - 1];
        sort(arr.begin(), arr.end(), greater());

        set<int> st;
        for (int i = 0; i < k; i++) {
            st.insert(arr[i]);
            arr[i] = -1;
        }

        if ((st.find(fav) != st.end()) &&
            (find(arr.begin(), arr.end(), fav) != arr.end())) {
            cout << "MAYBE" << nl;
        } else if ((st.find(fav) != st.end()) &&
                   !(find(arr.begin(), arr.end(), fav) != arr.end())) {
            cout << "YES" << nl;
        } else if (!(st.find(fav) != st.end()) &&
                   (find(arr.begin(), arr.end(), fav) != arr.end())) {
            cout << "NO" << nl;
        }
    }

    return 0;
}