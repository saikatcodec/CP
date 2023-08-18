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

#define N 100000
bitset<100002> primes;
vector<ll> numP;

void sieve() {
    primes.set();
    primes[0] = primes[1] = 0;

    for (ll i = 2; i * i <= N; i++) {
        if (primes[i]) {
            for (ll j = i * i; j <= N; j += i) {
                primes[j] = 0;
            }
        }
    }

    for (ll i = 2; i <= N; i++) {
        if (primes[i]) {
            numP.push_back(i);
        }
    }
}

int main() {
    FIO;
    sieve();

    testCase(t) {
        ll n, m;
        cin >> m >> n;

        // Segmented Sieve
        bool segmnt[n - m + 1] = {false};

        for (auto ele : numP) {
            if (ele * ele > n) {
                break;
            }

            ll start = (m / ele) * ele;
            if (ele >= m && ele <= n) {
                start = 2 * ele;
            }

            for (ll i = start; i <= n; i += ele) {
                segmnt[i - m] = true;
            }
        }

        for (ll i = m; i <= n; i++) {
            if (!segmnt[i - m] && i != 1) {
                cout << i << nl;
            }
        }

        cout << nl;
    }

    return 0;
}