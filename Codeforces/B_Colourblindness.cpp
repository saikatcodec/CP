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

        string row1, row2;
        cin >> row1 >> row2;

        for (int i = 0; i < row1.size(); i++)
        {
            if (row1[i] == 'B' || row1[i] == 'G')
                row1[i] = 'G';
        }
        for (int i = 0; i < row2.size(); i++)
        {
            if (row2[i] == 'B' || row2[i] == 'G')
                row2[i] = 'G';
        }

        if (row1 == row2)
            cout << "YES" << nl;
        else
            cout << "NO" << nl;
    }

    return 0;
}