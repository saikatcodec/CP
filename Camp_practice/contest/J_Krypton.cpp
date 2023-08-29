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
int val[] = {10, 60, 280, 880, 1980, 3280, 6480};
int wt[] = {1, 6, 28, 88, 198, 328, 648};
int ext[2001] = {0};
int flag[2001];

int knapSack(int W, int n) {
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++) {
        for (w = W; w >= 0; w--) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];

            if (flag[w] == false) {
                K[i][w] += ext[w];
                flag[w] = true;
            }
        }
    }
    return K[n][W];
}

int main() {
    FIO;

    ext[1] = 8;
    ext[6] = 18;
    ext[28] = 28;
    ext[88] = 58;
    ext[198] = 128;
    ext[328] = 198;
    ext[648] = 388;

    int n;
    cin >> n;

    cout << knapSack(n, 7) << nl;

    return 0;
}