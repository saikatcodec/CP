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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int max1 = max(a, b);
        int max2 = max(c, d);

        cout << max1 + max2 << nl;
    }

    return 0;
}