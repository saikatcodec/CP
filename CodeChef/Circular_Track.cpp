#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, m;
        cin >> a >> b >> m;

        int difNum = m / 2 + 1;
        int ans = abs(a - b);

        if (ans >= difNum)
            ans = m - max(a, b) + min(a, b);

        cout << ans << endl;
    }

    return 0;
}