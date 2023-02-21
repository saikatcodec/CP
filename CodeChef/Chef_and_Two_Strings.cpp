#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str1, str2;
        int ques1 = 0, ques2 = 0, equal = 0, min = 0;
        int max = 0;
        cin >> str1 >> str2;

        for (int i = 0; i < str1.size(); i++)
        {
            if (str1[i] == '?' && str2[i] != '?')
                max++;
            else if (str1[i] == '?' && str2[i] == '?')
                max++;
            else if (str1[i] != '?' && str2[i] == '?')
                max++;
            if ((str1[i] != str2[i]) && (str1[i] != '?') && (str2[i] != '?'))
                min++;
        }

        if (equal < 1)
            ques1 += ques2;

        cout << min << " " << max + min << endl;
    }

    return 0;
}