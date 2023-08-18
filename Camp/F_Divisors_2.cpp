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

#define N 10000000
int primes[N + 1];

void sieve() {
    for (int i = 0; i <= N; ++i) {
        primes[i] = i;
    }
    for (int i = 4; i <= N; i += 2) {
        primes[i] = 2;
    }
    for (int i = 3; i * i <= N; ++i) {
        if (primes[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (primes[j] == j) {
                    primes[j] = i;
                }
            }
        }
    }
}

bool countDiv(int n) {
    int divs = 1;
    map<int, int> cnt;

    while (n > 1) {
        cnt[primes[n]]++;
        n /= primes[n];
    }

    bool flag = true;
    for (auto p : cnt) {
        if (p.second > 1) {
            flag = false;
        }
        divs *= (p.second + 1);
    }

    return divs > 3 && flag;
}

int32_t main() {
    FIO;
    sieve();

    vector<int> divisor;
    for (int i = 267; i <= 1000000; i++) {
        bool num = countDiv(i);
        if (num) {
            divisor.push_back(i);
        }
    }

    for (int i = 0; i < divisor.size(); i += 108) {
        cout << divisor[i] << nl;
    }

    return 0;
}