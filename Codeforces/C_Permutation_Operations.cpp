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

        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<pair<int, int>> def;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                def.push_back({arr[i] - arr[i + 1], i + 2});
            }
        }

        sort(def.begin(), def.end());
        reverse(def.begin(), def.end());
        int ans[n] = {0};
        int index = n - 1;
        for (int i = 0; i < def.size(); i++) {
            ans[index] = def[i].second;
            index--;
        }

        for (int i = 0; i <= index; i++) {
            ans[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << nl;
    }

    return 0;
}