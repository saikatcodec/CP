#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        ll newX = ex;
        ll newY = sy;
        ll s1 = sqrt(((sx - newX) * (sx - newX)) + ((sy - newY) * (sy - newY)));
        ll s2 = sqrt(((ex - newX) * (ex - newX)) + ((ey - newY) * (ey - newY)));

        if (abs(s1 - s2) % 2 == 0)
            cout << (min(s1, s2) * 2) + (abs(s1 - s2) * 2) << nl;
        else
            cout << (min(s1, s2) * 2) + (((abs(s1 - s2) - 1) * 2) + 1) << nl;
    }

    return 0;
}