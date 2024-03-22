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

    int n;
    cin >> n;

    string str[n];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    int maxLen = 0;
    for (auto &st : str) {
        int cnt = 0;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] == 'a') {
                cnt++;
            }
        }

        if (cnt == 1) {
            st.push_back('a');
        } else if (cnt & 1) {
            st.pop_back();
        }

        maxLen = max(maxLen, (int)st.size());
    }

    for (auto st : str) {
        int space = (maxLen / 2) - (st.size() / 2);
        for (int i = 0; i < space; i++) {
            cout << " ";
        }
        cout << st << nl;
    }

    return 0;
}