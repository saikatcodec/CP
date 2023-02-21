#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

string s;
vector<ll> v(10e6);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> s;
        for (ll i = 0; i < s.length(); i++)
        {
            v[i] = s[i];
        }
        
        sort(v.begin(), v.end());
    }

    return 0;
}