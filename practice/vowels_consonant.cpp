#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str, vowels = "aeiou", vWord = "", cWord = "";
        getline(cin, str);

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                if (vowels.find(str[i]) != -1)
                    vWord += str[i];
                else
                    cWord += str[i];
            }
        }

        cout << vWord << endl;
        cout << cWord << endl;
    }

    return 0;
}