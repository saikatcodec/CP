#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string n;
        getline(cin, n);

        if (n.length() == 2)
            cout << n[1] << endl;
        else
        {
            int min = n[0] - '0';
            for (int i = 0; i < n.length(); i++)
            {
                if (min > (n[i] - '0'))
                    min = n[i] - '0';
            }

            cout << min << endl;
        }
    }

    return 0;
}