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

#define N 1000002
int spf[N], bpf[N];

void sieve() {
    for (int i = 2; i < N; i++) {
        spf[i] = i;
        bpf[i] = i;
    }

    for (int i = 2; i < N; i++) {
        if (spf[i] == i) {
            for (int j = 2 * i; j < N; j += i) {
                bpf[j] = i;
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
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
    sieve();

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int lpf = spf[arr[i]];
        int gpf = bpf[arr[i]];

        int tmp = arr[i];
        map<int, int> divs;
        while (tmp != 1) {
            divs[spf[tmp]]++;
            tmp /= spf[tmp];
        }

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