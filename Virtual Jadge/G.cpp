#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops") 
#define ll long long
#define memset(a,x) memset(a,x,sizeof(a))
#define PI 3.1415926535897932384626433832795l 
#define ys cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const long double EPS = 1e-9;

void No_Brain() {
    int n; cin>>n;
    int mp[n+1], a[n+1];
    for(int i = 1; i<=n; i++) {
        cin>>a[i];
        mp[a[i]] = i;
    }
    
    int maxx = n;
    vector<int>v;
    for(int i = 1; i<=n-1; i++) {
       if(mp[maxx]==maxx) {
        maxx--;
       }
        v.push_back(mp[maxx]);
        int temp1 = a[mp[maxx]];
        int temp2 = a[mp[maxx]+1];
        //cerr<<mp[temp1]<<" "<<mp[temp2]<<'\n';
        swap(a[mp[maxx]], a[mp[maxx]+1]);
        swap(mp[temp1],mp[temp2]);
        
       
    }
    for(int i = 1; i<=n; i++) {
      cout<<a[i]<<" ";
    }
    if(is_sorted(a+1, a+n+1)) {
        for(auto x:v) {
            cout<<x<<'\n';
        }
    }
    //else cout<<-1<<'\n';


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        No_Brain();
    }
    return 0;
}