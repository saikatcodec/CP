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

        if (x < y)
            cout << "REPAIR" << nl;
        else if (x > y)
            cout << "NEW PHONE" << nl;
        else
            cout << "ANY" << nl;
    }

    return 0;
}