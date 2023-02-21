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

        float dif = abs((x - y));
        int res = ceil(dif / 2);
        cout << res << nl;
    }

    return 0;
}