#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int xc, yc, x, y, r;
        cin >> xc >> yc;
        cin >> r;
        cin >> x >> y;

        double pos = sqrt(pow((xc - x), 2) + pow((yc - y), 2));

        if (pos <= r)
            cout << "The point is inside the circle" << endl;
        else
            cout << "The point is not inside the circle" << endl;
    }

    return 0;
}