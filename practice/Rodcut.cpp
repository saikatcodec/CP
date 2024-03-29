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

int mem[100000];

int rodCut(int price[], int length){
    if(mem[length]==-1){
        int temp = -1;
        for (int i = 0; i <= length; i++) {
            temp = max(temp, price[i-1]+rodCut(price, length-1));
        }
        mem[length]=temp;
    }
    return mem[length];
}
int main() {
    FIO;
    memset(mem, -1, sizeof(mem));
    mem[0]=0;
    int length; cin>>length;
    int price[length]; 
    for (int i = 0; i < length; i++) {
        cin>>price[i];
    }
    cout<<rodCut(price, length)<<endl;
    return 0;
}