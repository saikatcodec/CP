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

    int q = 0;
    testCase(t) {
        string a, b;
        cin >> a >> b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = "";
        int len = min(a.size(), b.size());
        int c = 0;
        for (int i = 0; i < len; i++) {
            int tempA = a[i] - '0';
            int tempB = b[i] - '0';
            int sum = tempA + tempB + c;
            ans.push_back((sum % 10) + '0');
            c = sum / 10;
        }

        if (a.size() < b.size()) {
            swap(a, b);
        }
        for (int i = len; i < a.size(); i++) {
            int temp = a[i] - '0';
            int sum = temp + c;
            ans.push_back((sum % 10) + '0');
            c = sum / 10;
        }
        if (c > 0) {
            ans.push_back(c + '0');
        }

        reverse(ans.begin(), ans.end());
        cout << "Case #" << ++q << ": " << ans << nl;
    }

    return 0;
}