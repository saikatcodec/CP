#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string name, s = "Timur";
        cin >> n;
        cin >> name;

        map<char, int> mp;
        mp['T'] = 1;
        mp['i'] = 1;
        mp['m'] = 1;
        mp['u'] = 1;
        mp['r'] = 1;

        for (int i = 0; i < n; i++)
        {
            mp[name[i]]++;
        }

        if (all_of(mp.begin(), mp.end(), [](pair<char, int> p)
                   { return p.second == 2; }))
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }

    return 0;
}