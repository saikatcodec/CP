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
        int n;
        cin >> n;

        int sz = n * (n - 1) / 2;
        int arr[sz];
        map<int, int> fre;
        for (int i = 0; i < sz; i++) {
            cin >> arr[i];
            fre[arr[i]]++;
        }

        if (sz == 1) {
            for (int i = 0; i < n; i++) {
                cout << arr[0] << " ";
            }
            cout << nl;
        } else {
            int newArr[n] = {0};
            bool flag[n] = {false};
            int i = n - 1;
            for (auto &c : fre) {
                while (i >= 0 and flag[i] == false) {
                    if (c.second > i) {
                        if (flag[i] == false) {
                            newArr[i] = c.first;
                            c.second = c.second - i;
                            flag[i] = true;
                        }
                    } else {
                        if (flag[i] == false) {
                            newArr[c.second] = c.first;
                            flag[c.second] = true;
                            i--;
                            break;
                        }
                    }
                    i--;
                }
            }

            newArr[0] = newArr[1];
            for (int i = 0; i < n; i++) {
                cout << newArr[i] << " ";
            }
            cout << nl;
        }
    }

    return 0;
}