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

vector<ll> divisor(ll n) {
    vector<ll> div;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if ((n / i) != i) div.push_back(n / i);
        }
    }

    sort(div.begin(), div.end());
    return div;
}

int main() {
    FIO;

    int n;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll small = *min_element(arr, arr + n);
    vector<ll> div = divisor(small);

    ll ans = 1;
    auto it = div.rbegin();
    for (; it != div.rend(); it++) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] % (*it) != 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans = *it;
            break;
        }
    }

    vector<ll> divs = divisor(ans);
    cout << divs.size() << nl;

    return 0;
}