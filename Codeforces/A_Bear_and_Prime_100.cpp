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

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    FIO;

    int cnt = 0;

    for (int i = 2; i <= 50; i++) {
        if (isPrime(i)) {
            cout << i << endl;
            string str;
            cin >> str;

            if (str == "yes") {
                cnt++;
            }

            if (i * i <= 50) {
                cout << i * i << endl;
                string str;
                cin >> str;

                if (str == "yes") {
                    cnt += 2;
                }
            }
        }
    }

    if (cnt >= 2) {
        cout << "composite" << endl;
    } else {
        cout << "prime" << endl;
    }

    return 0;
}