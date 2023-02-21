#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string str, rev;
        getline(cin, str);

        rev = str;
        reverse(rev.begin(), rev.end());

        if (rev == str)
            cout << "Yes! It is Palindrome" << endl;
        else
            cout << "Sorry! It is not Palindrome" << endl;
    }

    return 0;
}