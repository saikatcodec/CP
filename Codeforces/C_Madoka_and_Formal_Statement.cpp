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
        int n;
        cin >> n;

        bool flag = false;

        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            if ((a[i] > b[i]))
            {
                flag = true;
                break;
            }
            else if (((b[i] - b[(i + 1) % n]) > 1) && (a[i] != b[i]))
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "NO" << nl;
        else
            cout << "YES" << nl;
    }

    return 0;
}