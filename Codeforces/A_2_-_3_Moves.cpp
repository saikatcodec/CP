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
        int n, ans;
        cin >> n;

        if (n % 3 == 0)
            ans = n / 3;
        else if (n % 3 == 1)
        {
            ans = (n / 3) + 2;
            if ((n - 4) % 3 == 0 && (n - 4) > 0)
                ans = min(ans, ((n - 4) / 3) + 2);
        }
        else if (n % 3 == 2)
        {
            ans = (n / 3) + 1;
        }

        if (n % 2 == 0)
            ans = min(ans, n / 2);

        cout << ans << nl;
    }

    return 0;
}