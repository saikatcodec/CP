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
        char ch[4];
        map<char, int> mp;

        for (int i = 0; i < 4; i++)
        {
            cin >> ch[i];
            mp[ch[i]]++;
        }

        cout << mp.size() - 1 << nl;
    }

    return 0;
}
