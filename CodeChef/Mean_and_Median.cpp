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
        int x, y;
        cin >> x >> y;

        int twoV = (x * 3) - y;
        if (twoV < 0)
            cout << twoV << " " << y << " " << 0 << nl;
        else
        {
            cout << 0 << " " << y << " " << twoV << nl;
        }
    }

    return 0;
}