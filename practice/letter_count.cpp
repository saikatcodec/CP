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
        int count[26] = {0};
        getline(cin, str);

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                count[str[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                cout << char('a' + i) << " = " << count[i] << endl;
        }

        cout << endl;
    }

    return 0;
}