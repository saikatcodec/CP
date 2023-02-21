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
        long long a, b, n, res;
        cin >> a >> b >> n;

        if (a % b == 0)
            res = -1;
        else
        {
            long long div = ceil(n * 1.0 / a);

            while (true)
            {
                long long prod = a * div;
                if (prod % b != 0)
                {
                    res = prod;
                    break;
                }
                div++;
            }
        }

        cout << res << nl;
    }

    return 0;
}