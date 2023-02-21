#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string str[n];
        for (int i = 0; i < n; i++)
            cin >> str[i];

        int dif = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    dif += abs(str[i][k] - str[j][k]);
                }
                ans = min(ans, dif);
                dif = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}