#include <bits/stdc++.h>
using namespace std;

string rightShift(string str)
{
    int n = str.length();
    string newStr = str;
    newStr.pop_back();
    return str[n - 1] + newStr;
}

string leftShift(string str)
{
    int n = str.length();
    string newStr = str;
    newStr.erase(newStr.begin(), newStr.begin() + 1);
    return newStr + str[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string str, ans;
        cin >> str;

        if (str.length() == 1)
        {
            cout << "YES\n";
            continue;
        }

        string rgtShft = rightShift(str);
        string lftShft = leftShift(str);

        if (rgtShft == lftShft)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}