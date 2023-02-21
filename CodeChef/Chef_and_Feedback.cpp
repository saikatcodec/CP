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

        if (str.find("101") != string::npos || str.find("010") != string::npos)
            cout << "Good" << endl;
        else
            cout << "Bad" << endl;
    }

    return 0;
}