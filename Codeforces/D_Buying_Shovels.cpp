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

vector<int> primeFactor(int n) {
    vector<int> pf;

    while (n % 2 == 0) {
        pf.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i++) {
        if (n % i == 0) {
            pf.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        pf.push_back(n);
    }

    sort(pf.begin(), pf.end());
    return pf;
}

int main() {
    FIO;

    testCase(t) {
        int n, k;
        cin >> n >> k;

        if (n <= k) {
            cout << 1 << nl;
        } else {
            vector div = primeFactor(n);

            for (int v : div) {
                cerr << v << " ";
            }
            cerr << nl;

            int p1 = -1, val = 1;
            for (int v : div) {
                val *= v;
                int tmp = n / val;
                if (k >= tmp) {
                    p1 = tmp;
                    break;
                }
            }

            int p2 = -1;
            val = 1;
            vector<int>::reverse_iterator it;
            for (it = div.rbegin(); it != div.rend(); it++) {
                val *= (*it);
                int tmp = n / val;
                if (k >= tmp) {
                    p2 = tmp;
                    break;
                }
            }

            cout << min(p1, p2) << nl;
        }
    }

    return 0;
}