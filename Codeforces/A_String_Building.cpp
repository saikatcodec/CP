#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s, ans;
        int a = 0, b = 0;
        cin >> s;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
            {
                if (b == 1)
                {
                    ans = "NO";
                    break;
                }

                a++;
                b = 0;
            }
            else
            {
                if (a == 1)
                {
                    ans = "NO";
                    break;
                }

                b++;
                a = 0;
            }

            if (a != 1 && b != 1)
                ans = "YES";
            else
                ans = "NO";
        }

        cout << ans << endl;
    }

    return 0;
}