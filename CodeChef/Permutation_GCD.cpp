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
        int n, x;
        cin >> n >> x;

        vector<int> v(n);
        int maxRan = (n & 1) ? (n * 2 - 1) : n * 2;

        if (x < n || x > maxRan)
            cout << "-1";
        else if (x == maxRan)
        {
            for (int i = n; i >= 1; i--)
                cout << i << " ";
        }
        else if (x == n)
        {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
        }
        else
        {
            cout << x - n + 1 << " ";
            for (int i = 1; i <= n; i++)
            {
                if (i != x - n + 1)
                    cout << i << " ";
            }
        }
        cout << nl;
    }

    return 0;
}