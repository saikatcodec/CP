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
        int n;
        cin >> n;

        int arr[n];
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        int maxEle = *max_element(arr, arr + n);
        int minEle = *min_element(arr, arr + n);
        
        ll ans = 0;
        int y;
        int diff = maxEle - minEle;
        for(int i = 0; i<n; i++) {
            if(diff >= arr[i]) {
                y = arr[i] + diff ;
                if(mp[y] > 0) ans+=(mp[y] * 1LL);
                if(y == arr[i])ans--;
            }
            else {
                y = arr[i] - diff ;
                if(mp[y]>0)ans+=(mp[y]*1LL);
                if(y == arr[i])ans--;
            }
        }

        cout << ans << nl;
    }

    return 0;
}