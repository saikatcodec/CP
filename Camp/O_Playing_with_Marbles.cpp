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
bitset<N + 1> p;
vector<ll> primes;

void sieve() {
    p.set();
    p[0] = p[1] = 0;

    for (ll i = 3; i * i <= N; i += 2) {
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

int main() {
    FIO;
    sieve();

    ll n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        ll m = n;

        vector<ll> factors;
        ll cnt = 1;
        for (auto prime : primes) {
            if (prime * prime > n) {
                break;
            }

            ll tmp = 0;
            while (n % prime == 0) {
                factors.push_back(prime);
                n /= prime;
                tmp++;
            }

            cnt *= (tmp + 1);
        }

        if (n > 1) {
            factors.push_back(n);
            cnt *= 2;
        }
        cnt = (cnt + 1) / 2;
        sort(factors.begin(), factors.end());

        cout << m << " = ";
        for (int i = 0; i < factors.size(); i++) {
            cout << factors[i];
            if (i != factors.size() - 1) {
                cout << " * ";
            }
        }
        cout << nl;
        cout << "With " << m << " marbles, "
             << cnt << " different rectangles can be constructed." << nl;
    }

    return 0;
}