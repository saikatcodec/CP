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

        char rob[n][m];
        int rfPos = -1, rlPos = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> rob[i][j];
                if (rob[i][j] == 'R' && rfPos == -1)
                    rfPos = j;
                else if (rob[i][j] == 'R')
                    rlPos = min(rlPos, j);
            }
        }

        if (rfPos <= rlPos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}