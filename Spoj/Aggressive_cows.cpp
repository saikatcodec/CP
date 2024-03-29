#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// clang-format on

bool check(ll arr[], ll n, ll c, ll low, ll high, ll minStall) {
    ll init = arr[0];
    ll cow = 1;

    for (ll i = 1; i < n; i++) {
        if ((arr[i] - init) >= minStall) {
            init = arr[i];
            cow++;
        }

        if (cow == c) {
            return true;
        }
    }

    return false;
}

int main() {
    FIO;

    testCase(t) {
        ll n, c;
        cin >> n >> c;

        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll low = 1, high = 1e9;
        while (low < high) {
            ll mid = (low + high + 1) / 2;

            bool orNot = check(arr, n, c, low, high, mid);

            if (orNot) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        cout << low << nl;
    }

    return 0;
}