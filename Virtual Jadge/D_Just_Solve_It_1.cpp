#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define int long long
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

map<int, int> primeDiv(int n) {
    map<int, int> divs;

    while (n % 2 == 0) {
        divs[2]++;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            divs[i]++;
            n /= i;
        }
    }

    if (n > 2) {
        divs[n]++;
    }

    return divs;
}

int calPow(int p, int e) {
    int r = 1;

    for (int i = 1; i <= e; i++) {
        r *= p;
    }

    return r;
}

int32_t main() {
    FIO;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        map<int, int> divs = primeDiv(arr[i]);

        int lpf = (*divs.begin()).first;
        int gpf = (*divs.rbegin()).first;
        int w = divs.size();
        int ohm = 0, d = 1;
        for (auto p : divs) {
            ohm += p.second;
            d *= (p.second + 1);
        }

        int sumOfDiv = 1;
        for (auto p : divs) {
            sumOfDiv *= (calPow(p.first, p.second + 1) - 1) / (p.first - 1);
        }

        cout << lpf << " " << gpf << " " << w << " " << ohm << " " << d << " "
             << sumOfDiv << nl;
    }

    return 0;
}