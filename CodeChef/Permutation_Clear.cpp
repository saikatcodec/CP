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
        int n;
        cin >> n;

        int arl[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arl[i];
        }

        int nb;
        cin >> nb;

        bool arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = false;
        }

        for (int i = 0; i < nb; i++)
        {
            int a;
            cin >> a;
            arr[a - 1] = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[arl[i] - 1])
                continue;
            cout << arl[i] << " ";
        }
        cout << nl;
    }

    return 0;
}