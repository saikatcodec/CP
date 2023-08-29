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

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n*fact(n-1);
}
 
int nPr(int n, int r)
{
    return fact(n)/fact(n-r);
}

int main() {
    FIO;

    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int k; cin>>k;
        int zero =0;
        for(int i =0; i<=s.size(); i++){
            if(s[i]=='0') zero = 1;
        }
        ll temp = nPr(s.size(), k);
        ll z = 0;
        if(zero){
            z = nPr(s.size()-1, k-1);
        }
        cout<<temp-z<<'\n';
    }

    return 0;
}