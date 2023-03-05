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

void printSubArrays(vector<int> arr, int start, int end, vector<int> &ans) {
    if (end == arr.size())
        return;
    else if (start > end)
        printSubArrays(arr, 0, end + 1, ans);
    else {
        int maxE = INT_MIN;
        for (int i = start; i < end; i++)
            maxE = max(maxE, arr[i]);
        maxE = max(maxE, arr[end]);
        ans.push_back(maxE);
        printSubArrays(arr, start + 1, end, ans);
    }
    return;
}

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            arr.push_back(a);
        }

        vector<int> ans;

        printSubArrays(arr, 0, 0, ans);

        for (auto ele : ans) {
            cout << ele << " ";
        }
        cout << nl;
    }
    return 0;
}