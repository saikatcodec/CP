#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string str;
    cin >> str;

    vector<char> braces;
    braces.push_back(str[0]);
    for (int i = 1; i < str.length(); i++)
    {
        if (braces.back() == '(' && str[i] == ')')
            braces.pop_back();
        else
            braces.push_back(str[i]);
    }

    if (braces.empty())
        cout << "Yes" << nl;
    else
        cout << "No" << nl;

    return 0;
}