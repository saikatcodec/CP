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

        ll arr[n], prefix[n], ans = 0;
        bool check[n], flag = true;
        ll maxFre;
        map<ll, ll> mp;

        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (arr[0] == 0)    
            flag = false;

        for (ll i = 0; i < n; i++) {
            if (i + 1 < n) {
                if (arr[i + 1] == 0)   
                    check[i] = true;
                else
                    check[i] = false;
            } else {
                check[i] = true;
            }
        }

        prefix[0] = arr[0];
        for (ll i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        for(ll i = 0; i < n; i++) {
            if(check[i] == false){
                mp[prefix[i]]++;
                maxFre=max(maxFre, mp[prefix[i]]);
            } else {
                mp[prefix[i]]++;
                maxFre = max(maxFre, mp[prefix[i]]);
                if(flag) {
                    ans = ans + mp[0];
                    maxFre = 0;
                    mp.clear();
                    flag = false;
                } else {
                    ans = ans + maxFre;
                    mp.clear();
                    maxFre = 0;
                }
            }
        }

        cout << ans << nl;
    }

    return 0;
}