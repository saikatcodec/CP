#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define nl "\n"
#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define M 1000001
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void sieve(int *p) {
    p[2] = 1;
    for (int i = 3; i < M; i += 2) {
        p[i] = 1;
    }

    for (int i = 2; i * i < M; i++) {
        if (p[i] == 1) {
            for (int j = i * i; j < M; j += i) {
                p[j] = 0;
            }
        }
    }
}

int main() {
    FIO;

    int p[M] = {0};
    sieve(p);

    int cumSum[M] = {0};
    for (int i = 1; i < M; i++) {
        cumSum[i] = cumSum[i - 1] + p[i];
    }

    testCase(t) {
        int a, b;
        cin >> a >> b;
        
        cout << cumSum[b] - cumSum[a - 1] << nl;
    }

    return 0;
}