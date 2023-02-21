#include <bits/stdc++.h>
#define end "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        long long ans;
        cin >> n >> m;

        if (n == 1)
            cout << (m * (m + 1)) / 2 << end;
        else if (m == 1)
            cout << (n * (n + 1)) / 2 << end;
        else
        {
            ans = (m * (m + 1)) / 2;
            for (int i = 2; i <= n; i++)
                ans += (i * m);

            cout << ans << end;
        }
    }

    return 0;
}