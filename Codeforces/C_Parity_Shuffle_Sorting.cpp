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
        ll n;
        cin >> n;

        ll arr[n + 1];
        for (ll i = 1; i <= n; i++)
            cin >> arr[i];

        cout << n - 1 << endl;
        if (n > 1)
            cout << 1 << " " << n << endl;

        ll x = (arr[1] + arr[n]) % 2 ? arr[1] : arr[n];
        for (ll i = 2; i < n; i++)
        {
            if ((x + arr[i]) % 2)
                cout << 1 << " " << i << endl;
            else
                cout << i << " " << n << endl;
        }
    }

    return 0;
}