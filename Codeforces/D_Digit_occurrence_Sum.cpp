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

map<int, int> freq;

vector<int> extractDigit(int n) {
    vector<int> digit;

    while (n > 0) {
        int tmp = n % 10;
        n /= 10;
        digit.push_back(tmp);
    }

    return digit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    pbds st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }

    for (int ele : st) {
        vector<int> dgts = extractDigit(ele);

        for (int i : dgts) {
            freq[i]++;
        }
    }

    while (q--) {
        char tag;
        int k;
        cin >> tag >> k;

        if (tag == '+') {
            auto it = st.find(k);

            vector<int> dgts = extractDigit(k);
            if (it != st.end()) {
                st.erase(it);

                for (int d : dgts) {
                    freq[d]--;
                }
            } else {
                st.insert(k);
                for (int d : dgts) {
                    freq[d]++;
                }
            }
        } else if (tag == '-') {
            if (st.size() >= k) {
                auto it = st.find_by_order(st.size() - k);
                vector<int> dgts = extractDigit(*it);
                st.erase(it);
                for (int d : dgts) {
                    freq[d]--;
                }
            }
        } else {
            auto it = st.find(k);
            if (it != st.end()) {
                vector<int> dgts = extractDigit(k);

                int ans = 0;
                for (int d : dgts) {
                    ans += freq[d];
                }
                cout << ans << nl;
            } else {
                cout << -1 << nl;
            }
        }
    }

    return 0;
}