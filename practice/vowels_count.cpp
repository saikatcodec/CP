#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str, vowels = "aeiou";
        getline(cin, str);

        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (vowels.find(str[i]) != -1)
                count++;
        }

        cout << "Number of vowels = " << count << endl;
    }

    return 0;
}