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

int const N = 1000002;
bool notPrim[N];
void sieve() {
    for (ll i = 2; i * i < N; i++) {
        if (!notPrim[i]) {
            for (ll j = i * i; j < N; j += i) {
                if (!notPrim[j]) {
                    notPrim[j] = true;
                }
            }
        }
    }
}

int main() {
    FIO;
    sieve();

    ll n;
    cin >> n;

    ll arr[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (ll i = 0; i < n; i++) {
        ll val = floor(sqrt(arr[i]));
        if (arr[i] == 1) {
            cout << "NO" << nl;
        } else if ((val == ceil(sqrt(arr[i]))) && (!notPrim[val])) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}