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

bool arrComp(int sz, int arr1[], vector<int> arr2) {
    sort(arr1, arr1 + sz);
    sort(arr2.begin(), arr2.end());

    for (int i = 0; i < sz; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    FIO;

    testCase(t) {
        int n, c, d;
        cin >> n >> c >> d;

        int sz = n * n;
        int arr[sz];
        for (int i = 0; i < sz; i++) {
            cin >> arr[i];
        }

        int minEle = *min_element(arr, arr + sz);
        vector<int> newArr, fRow;
        newArr.push_back(minEle);

        for (int i = 0; i < n - 1; i++) {
            int last = *newArr.rbegin();
            newArr.push_back(last + c);
        }

        fRow.push_back(minEle + d);
        for (int i = 0; i < n - 2; i++) {
            int last = *fRow.rbegin();
            fRow.push_back(last + d);
        }

        for (int ele : fRow) {
            newArr.push_back(ele);
            newArr.push_back(ele + c);
            for (int i = 0; i < n - 2; i++) {
                int last = *newArr.rbegin();
                newArr.push_back(last + c);
            }
        }

        if (sz == newArr.size()) {
            if (arrComp(sz, arr, newArr)) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}