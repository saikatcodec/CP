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

vector<int> primeDivisor(int n) {
    vector<int> div;

    while (n % 2 == 0) {
        div.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            div.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        div.push_back(n);
    }

    return div;
}

int main() {
    FIO;

    testCase(t) {
        int n;
        cin >> n;

        vector<int> div = primeDivisor(n);
        if (div.size() < 3) {
            cout << "NO" << nl;
        } else {
            int first = div[0];

            int second = 1, i = 1;
            for (; i < div.size(); i++) {
                second *= div[i];
                if (first != second) {
                    i++;
                    break;
                }
            }

            int third = 1;
            for (; i < div.size(); i++) {
                third *= div[i];
            }

            if (first != 1 && second != 1 && third != 1) {
                set<int> ff;
                ff.insert(first);
                ff.insert(second);
                ff.insert(third);

                if (ff.size() == 3) {
                    cout << "YES" << nl;
                    cout << first << " " << second << " " << third << nl;
                } else {
                    cout << "NO" << nl;
                }
            } else {
                cout << "NO" << nl;
            }
        }
    }

    return 0;
}