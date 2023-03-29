#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// clang-format off
#define nl "\n"
#define ll long long
#define mod 1000000007
#define inf 1e18
#define testCase(x) int x; cin >> x; while (x--)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// clang-format on

#define MAXN 5000002
int spf[MAXN];

void sieve() {
    for (int i = 0; i < MAXN; i++) {
        spf[i] = i;
    }

    for (int i = 4; i < MAXN; i += 2) {
        spf[i] = 2;
    }

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

bool hasTwoFactor(int n) {
    set<int> factors;
    int cnt = 0;

    while (n != 1) {
        factors.insert(spf[n]);
        cnt++;
        n /= spf[n];
    }

    if (factors.size() == 2 && cnt == 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    FIO;

    sieve();
    vector<int> ans;
    for (int i = 1; i < MAXN; i++) {
        if (hasTwoFactor(i)) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << nl;

    testCase(t) {
        int n;
        cin >> n;

        cout << ans[n - 1] << nl;
    }

    return 0;
}