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

        string sen;
        cin >> sen;

        multiset<char> x, y;

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                x.insert(sen[i]);
            else
                y.insert(sen[i]);
        }

        if (x == y)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}