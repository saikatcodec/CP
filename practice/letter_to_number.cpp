#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str;
        getline(cin, str);

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                cout << str[i] - 'A' + 1;
        }

        cout << endl;
    }

    return 0;
}