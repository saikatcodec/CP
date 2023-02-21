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
        int n, ans = 0;
        cin >> n;

        string str;
        cin >> str;

        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == '1' && (i == 0 || str[i - 1] == '0'))
                ans++;
        }

        if (str.back() == '0')
            ans++;

        cout
            << ans << endl;
    }

    return 0;
}