#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int fNum, lNum, div;
        cin >> fNum >> lNum >> div;

        for (int i = fNum; i <= lNum; i++)
        {
            if (i % div == 0)
                cout << i << endl;
        }

        cout << endl;
    }

    return 0;
}