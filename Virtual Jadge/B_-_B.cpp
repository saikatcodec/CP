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

int main() {
    FIO;

    int t, q = 0;
    cin >> t;

    while (t--) {
        string cmd, url = "http://www.lightoj.com/";
        stack<string> back, forw;

        cout << "Case " << ++q << ": " << nl;
        while (true) {
            cin >> cmd;
            if (cmd == "VISIT") {
                back.push(url);
                cin >> url;
                stack<string> dummy;
                forw.swap(dummy);

                cout << url << nl;
            } else if (cmd == "BACK") {
                if (back.empty()) {
                    cout << "Ignored" << nl;
                } else {
                    forw.push(url);
                    url = back.top();
                    back.pop();
                    cout << url << nl;
                }
            } else if (cmd == "FORWARD") {
                if (forw.empty()) {
                    cout << "Ignored" << nl;
                } else {
                    back.push(url);
                    url = forw.top();
                    forw.pop();
                    cout << url << nl;
                }
            } else if (cmd == "QUIT") {
                break;
            }
        }
    }

    return 0;
}