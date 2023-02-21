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
        char dummy = getchar();
        string patt[8];

        for (int i = 0; i < 8; i++)
        {
            cin >> patt[i];
        }

        for (int row = 1; row < 8; row++)
        {
            for (int col = 1; col < 8; col++)
            {
                if (patt[row][col] == '#')
                {
                    if (patt[row - 1][col - 1] == '#' && patt[row - 1][col + 1] == '#' && patt[row + 1][col - 1] == '#' && patt[row + 1][col + 1] == '#')
                        cout << row + 1 << " " << col + 1 << endl;
                }
            }
        }
    }

    return 0;
}