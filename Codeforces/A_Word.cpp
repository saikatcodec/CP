#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int lower = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            lower++;
    }

    if (str.length() - lower > lower)
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    else
        transform(str.begin(), str.end(), str.begin(), ::tolower);

    cout << str << endl;

    return 0;
}