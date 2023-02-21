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
        cin >> n;

        string word[3][n];
        map<string, int> mp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> word[i][j];
                mp[word[i][j]]++;
            }
        }

        vector<int> ans(3, 0);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i] = ans[i] + (3 - ((mp[word[i][j]] == 1) ? 0 : mp[word[i][j]]));
            }
        }

        for (int i = 0; i < 3; i++)
        {
            cout << ans[i] << " ";
        }
        cout << nl;
    }

    return 0;
}