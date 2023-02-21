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

        string s, r;
        cin >> s;
        cin >> r;

        bool init = true;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != r[i])
                init = !init;
        }

        if (init)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}