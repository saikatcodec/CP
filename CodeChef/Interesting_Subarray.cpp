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
        ll n, minP, maxP;
        cin >> n;

        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll maxV = *max_element(arr, arr + n);
        ll minV = *min_element(arr, arr + n);

        if (maxV < 0)
        {
            minP = maxV * maxV;
            maxP = minV * minV;
        }
        else if (maxV == 0)
        {
            if (minV < 0)
            {
                maxP = minV * minV;
                minP = 0;
            }
            else
            {
                maxP = 0;
                minP = 0;
            }
        }
        else
        {
            if (minV > 0)
            {
                minP = minV * minV;
                maxP = maxV * maxV;
            }
            else if (minV < 0)
            {
                minP = maxV * minV;
                maxP = max((maxV * maxV), (minV * minV));
            }
            else
            {
                minP = 0;
                maxP = maxV * maxV;
            }
        }

        cout << minP << " " << maxP << nl;
    }

    return 0;
}