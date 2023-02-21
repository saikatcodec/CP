#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int rect[n][m];
        int max_i = 0, max_j = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> rect[i][j];

                if (rect[i][j] > rect[max_i][max_j])
                {
                    max_i = i;
                    max_j = j;
                }
            }
        }

        int h = max(max_i + 1, n - max_i);
        int w = max(max_j + 1, m - max_j);

        cout << h * w << "\n";
    }

    return 0;
}