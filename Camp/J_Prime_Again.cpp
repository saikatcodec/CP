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

#define N 10000000
bitset<10000002> p;
vector<ll> primes;

void sieve() {
    p.set();
    p[0] = p[1] = 0;

    for (ll i = 3; i <= N; i += 2) {
        if (p[i]) {
            for (ll j = i * i; j <= N; j += 2 * i) {
                p[j] = 0;
            }
        }
    }

    primes.push_back(2);
    for (ll i = 3; i <= N; i += 2) {
        if (p[i]) {
            primes.push_back(i);
        }
    }
}

bool isPrime(ll n) {
    if (n <= N) {
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        return p[n];
    }

    for (auto ele : primes) {
        if (ele * ele > n) {
            break;
        }

        if (n % ele == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    FIO;
    sieve();

    testCase(t) {
        ll n;
        cin >> n;

        for (ll i = n - 1; i >= 3; i--) {
            if (isPrime(i)) {
                cout << i << nl;
                break;
            }
        }
    }

    return 0;
}