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

vector<string> splitInto(string rec) {
    vector<string> words;
    istringstream line(rec);
    string word;

    while (line >> word) {
        words.push_back(word);
    }

    return words;
}

int main() {
    FIO;

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string rec;
        getline(cin, rec);

        map<string, bool> dak;
        string goes, rare;

        do {
            string an;
            cin >> an >> goes >> rare;

            dak[rare] = true;
        } while (goes == "goes");
        string dummy;
        getline(cin, dummy);

        vector<string> ans, words = splitInto(rec);

        for (auto word : words) {
            if (!dak[word]) {
                ans.push_back(word);
            }
        }

        for (auto ele : ans) {
            cout << ele << " ";
        }
        cout << nl;
    }

    return 0;
}