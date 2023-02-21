#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, c, x, z = 0;
        ;
        cin >> n >> m;
        ll ans;
        if (m % n == 0)
            cout << m << " " << n << endl;

        else
        {

            for (int i = n; i <= m; i++)
            {
                ans = abs(i - m + (m % i));
                if (ans >= z)
                {
                    z = ans;
                    x = i;
                    c = m - (m % i);
                }
            }
            cout << x << " " << c << endl;
        }
    }
    return 0;
}