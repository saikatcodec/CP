#include <bits/stdc++.h>
using namespace std;

int occurrence(string str, char ch)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ch)
            count++;
    }

    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str;
        char oneCh;

        cin.ignore();
        getline(cin, str);
        oneCh = getchar();

        int count = occurrence(str, oneCh);
        if (count <= 0)
            cout << "'" << oneCh << "'"
                 << " is not present" << endl;
        else
            cout << "Occurrence of '" << oneCh << "' in '" << str << "' = " << count << endl;
    }

    return 0;
}