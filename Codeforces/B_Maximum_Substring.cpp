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
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main() {
    FIO;

    testCase(t) {
        ll n;
        cin >> n;

        string str;
        cin >> str;

        ll cost = 0, cnt = 1;
        if (n == 1) {
            cost = 1;
        }
        else {
            char flag = str[0];
            for (ll i = 1; i < n; i++) {
                if (flag == str[i]) {
                    cnt++;
                } else {
                    cnt = 1;
                    flag = str[i];
                }

                cost = max(cost, cnt * cnt);
            }

            ll zCnt = 0, oCnt = 0;
            for (ll i = 0; i < n; i++) {
                if (str[i] == '0') 
                    zCnt++;
                else 
                    oCnt++;
            }

            cost = max(cost, zCnt * oCnt);
        }
        
        cout << cost << nl;
    }

    return 0;
}