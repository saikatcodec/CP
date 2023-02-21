#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        char ch;
        cin >> ch;

        if (ch >= 'a' && ch <= 'z')
            cout << "Lowercase Character" << endl;
        else if (ch >= 'A' && ch <= 'Z')
            cout << "Uppercase Character" << endl;
        else if (ch >= '0' && ch <= '9')
            cout << "Numerical Character" << endl;
        else
            cout << "Special Character" << endl;
    }

    return 0;
}