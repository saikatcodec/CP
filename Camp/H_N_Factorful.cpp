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

#define N 1000000
int numD[N + 1];
bitset<N + 1> p;
int pre[11][N + 1];

void sieve() {
    p.set();
    p[0] = p[1] = 0;

    for (int i = 2; i <= N; i += 1) {
        if (p[i]) {
            for (int j = i; j <= N; j += i) {
                numD[j]++;
                p[j] = 0;
            }
        }
    }
}

void precompute() {
    for (int i = 1; i <= N; i++) {
        if (numD[i] <= 10) {
            pre[numD[i]][i]++;
        }
    }

    for (int i = 0; i <= 10; i++) {
        for (int j = 1; j <= N; j++) {
            pre[i][j] += pre[i][j - 1];
        }
    }
}

int main() {
    FIO;

    sieve();
    precompute();

    testCase(t) {
        int a, b, n;
        cin >> a >> b >> n;

        cout << pre[n][b] - pre[n][a - 1] << nl;
    }

    return 0;
}