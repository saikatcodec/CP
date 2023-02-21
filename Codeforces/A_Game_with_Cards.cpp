#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int alice[n];
        for (int i = 0; i < n; i++)
            cin >> alice[i];

        int m;
        cin >> m;

        int bob[m];
        for (int i = 0; i < m; i++)
            cin >> bob[i];

        int alMax = *max_element(alice, alice + n);
        int bobMax = *max_element(bob, bob + m);

        if (alMax < bobMax)
        {
            cout << "Bob" << endl;
            cout << "Bob" << endl;
        }
        else if (alMax > bobMax)
        {
            cout << "Alice" << endl;
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Alice" << endl;
            cout << "Bob" << endl;
        }
    }

    return 0;
}