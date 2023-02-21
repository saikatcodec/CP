#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, ans;
        cin >> n;

        ans = 2 * floor((n - 1) / 5);
        int rmdr = (n - 1) % 5;

        if (rmdr == 1 || rmdr == 2 || rmdr == 3)
            ans++;
        else if (rmdr == 4)
            ans += 2;

        cout << ans << "\n";
    }

    return 0;
}