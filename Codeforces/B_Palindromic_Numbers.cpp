#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

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

        string num, ans;
        cin >> num;

        if (num[0] == '9')
        {
            int carry = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                int x = num[i] - '0';
                int y;
                x += carry;
                if (x > 1)
                {
                    y = 11 - x;
                    carry = 1;
                }
                else
                {
                    y = 1 - x;
                    carry = 0;
                }

                ans.append(to_string(y));
            }
            reverse(ans.begin(), ans.end());
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int y = 9 - (num[i] - '0');
                ans.append(to_string(y));
            }
        }

        cout << ans << nl;
    }

    return 0;
}