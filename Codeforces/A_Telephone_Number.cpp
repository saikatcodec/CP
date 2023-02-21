#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string str;
        cin >> str;

        int dif = n - 11;
        bool flag = false;
        for (int i = 0; i <= dif; i++)
        {
            if (str[i] == '8')
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}