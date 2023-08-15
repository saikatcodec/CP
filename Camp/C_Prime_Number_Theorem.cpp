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

#define N 100000000
bitset<100000002> primes;
vector<int> numP(N + 2);

void sieve() {
    primes.set();
    primes[0] = primes[1] = 0;

    for (ll i = 3; i * i <= N; i += 2) {
        if (primes[i]) {
            for (ll j = i * i; j <= N; j += i + i) {
                primes[j] = 0;
            }
        }
    }

    numP[2] = 1;
    int cnt = 1;
    for (int i = 3; i <= N; i++) {
        if (primes[i] && i & 1) {
            cnt++;
        }

        numP[i] = cnt;
    }
}

int main() {
    FIO;
    sieve();

    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        int px = numP[n];
        double lnx = n * 1.0 / log(n * 1.0);

        double err = (fabs(px - lnx) / px) * 100;
        cout << ps(err, 1) << nl;
    }

    return 0;
}