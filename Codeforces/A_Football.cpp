#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 1;
    string str;
    cin >> str;

    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            cnt++;
            if (cnt >= 7)
                break;
        }
        else
            cnt = 1;
    }

    if (cnt >= 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}