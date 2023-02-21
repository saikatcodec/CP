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
// clang-format on
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        vector<int> facts;

        while (n % 2 == 0) {
            facts.push_back(2);
            n /= 2;
        }

        for (int i = 3; i <= sqrt(n); i = i + 2) {
            while (n % i == 0) {
                facts.push_back(i);
                n /= i;
            }
        }

        if (n > 2)
            facts.push_back(n);

        if (facts.size() == 1)
            cout << -1 << nl;
        else if (facts.size() == 2) {
            for (auto ele : facts) {
                cout << ele << " ";
            }
            cout << 1 << nl;
        } else if (facts.size() == 3) {
            for (auto ele : facts) {
                cout << ele << " ";
            }
            cout << nl;
        } else {
            int prod = 1;
            for (int i = 0; i < facts.size() - 2; i++) {
                prod *= facts[i];
            }
            int arr[3];
            arr[0] = prod;
            arr[1] = facts[facts.size() - 2];
            arr[2] = facts[facts.size() - 1];

            sort(arr, arr + 3);
            for (int i = 0; i < 3; i++) {
                cout << arr[i] << " ";
            }
            cout << nl;
        }
    }

    return 0;
}