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

vector<string> splitString(string s) {
    vector<string> part;

    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            part.push_back(ans);
            ans = "";
            continue;
        }

        ans.push_back(s[i]);
    }
    part.push_back(ans);

    if (part.size() < 3) {
        part.push_back("00");
    }

    return part;
}

int main() {
    FIO;

    string s, t;
    cin >> s >> t;

    vector<string> l, lt;
    l = splitString(s);
    lt = splitString(t);

    bool first = true, last = false;

    for (int i = 0; i < min(l.size(), lt.size()); i++) {
        int part1 = stoi(l[i]);
        int part2 = stoi(lt[i]);
        if (part1 == part2) {
            continue;
        } else if (part1 < part2) {
            first = false;
            last = true;
            break;
        } else {
            break;
        }
    }

    if (first && !last) {
        cout << s << nl;
    } else {
        cout << t << nl;
    }

    return 0;
}