#include <bits/stdc++.h>
using namespace std;

void printTime(string hurs, string timeStr)
{
    string newTime = timeStr.substr(0, timeStr.length() - 2);
    newTime.replace(newTime.begin(), newTime.begin() + 2, hurs);
    cout << newTime << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string timeStr;
    cin >> timeStr;

    if (timeStr[timeStr.length() - 2] == 'P')
    {
        int hur = stoi(timeStr.substr(0, 2));
        if (hur != 12)
            hur += 12;

        printTime(to_string(hur), timeStr);
    }
    else
    {
        string str;
        int hur = stoi(timeStr.substr(0, 2));

        if (hur == 12)
            str = "00";
        else
            str = timeStr.substr(0, 2);

        printTime(str, timeStr);
    }

    return 0;
}