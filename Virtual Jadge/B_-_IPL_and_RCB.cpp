#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

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
            cout << 0 << nl;
        else
            cout << x - y << nl;
    }

    return 0;
}