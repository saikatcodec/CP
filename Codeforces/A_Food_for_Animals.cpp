#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, c, x, y, dif = 0;
        cin >> a >> b >> c >> x >> y;

        bool flag = true;
        if (x > a)
            dif += (x - a);
        if (y > b)
            dif += (y - b);

        if (dif <= c)
            flag = true;
        else
            flag = false;

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}