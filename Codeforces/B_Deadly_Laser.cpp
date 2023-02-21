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
        int ans = -1;
        int n, m, x, y, d;
        cin >> n >> m >> x >> y >> d;
        if ((x - d - 1) >= 1 && (y + d + 1) <= m)
        {
            ans = n + m - 2;
        }
        else if ((x + d + 1) <= n && (y - d - 1) >= 1)
        {
            ans = n + m - 2;
        }
        cout << ans << nl;
    }

    return 0;
}