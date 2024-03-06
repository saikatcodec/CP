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

        int arr[n];
        vector<int> ele;
        map<int, int> fre;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            fre[arr[i]]++;
            ele.push_back(arr[i]);
        }

        sort(ele.begin(), ele.end());
        auto it = unique(ele.begin(), ele.end());
        ele.resize(distance(ele.begin(), it));
        int maxOfarr = ele.size();

        for (int i = 0; i < ele.size(); i++) {
            if (i != ele[i]) {
                maxOfarr = i;
                break;
            }
        }

        bool flag = true;
        for (auto p : fre) {
            if (p.first < maxOfarr) {
                if (p.second < 2) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            int init = 1, end = 0;
            set<int> s1, s2;

            for (int i = 0; i < n; i++) {
                if ((s1.size() < maxOfarr) && (arr[i] < maxOfarr)) {
                    s1.insert(arr[i]);
                    end = i;
                }
            }

            for (int i = end + 1; i < n; i++) {
                if (arr[i] < maxOfarr) {
                    s2.insert(arr[i]);
                }
            }

            bool flag = false;
            if (s2.size() == maxOfarr) flag = true;

            if (flag) {
                cout << 2 << nl;
                cout << init << " " << end + 1 << nl;
                cout << end + 2 << " " << n << nl;
            } else {
                cout << -1 << nl;
            }
        } else {
            cout << -1 << nl;
        }
    }

    return 0;
}