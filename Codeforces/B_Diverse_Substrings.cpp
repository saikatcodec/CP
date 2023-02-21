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

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        string str;
        cin >> str;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            int maxF = 0, distinct = 0;

            for (int j = i; j < n && ++freq[str[j]] <= 10; j++) {
                maxF = max(maxF, freq[str[j]]);

                if (freq[str[j]] == 1) {
                    distinct++;
                }

                if (maxF <= distinct) {
                    ans++;
                }
            }
        }

        cout << ans << nl;
    }

    return 0;
}