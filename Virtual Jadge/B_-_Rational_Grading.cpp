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

int OctToDec(string n) {
    return stoi(n, 0, 8);
}

int hexToDeci(string n) {
    return stoi(n, 0, 16);
}

int main() {
    FIO;

    int t;
    string n;
    while (cin >> n >> t) {
    int out = 0;
        int num;
        if (n[0] == '0' && n[1] == 'x') {
            num = hexToDeci(n);
        } else if (n[0] == '0') {
            num = OctToDec(n);
        } else {
            num = stoi(n, 0, 10);
        }
        if (n == "0" && t == 0) {
            break;
        }

        while (t--) {
            string op;
            int i;
            cin >> op >> i;
            // cout<<"n = "<<num<<endl;
            if (op == "++i") {
                if (++num == i)
                    out++;
                else
                    num = i;
            }
            else if (op == "i++") {
                if (num++ == i)
                    out++;
                else
                    num = ++i;
            }
            else if (op == "--i") {
                if (--num == i)
                    out++;
                else
                    num = i;
            }
            else if (op == "i--") {
                if (num-- == i)
                    out++;
                else
                    num = --i;
            } else {
                if(num==i) out++;
                else num=i;
            }
        }
        cout<<out<<endl;
    }

    return 0;
}