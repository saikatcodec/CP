#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, lastMax, lastMin;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool flag = true;
        lastMax = lastMin = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= lastMax)
                lastMax = arr[i];
            else if (arr[i] <= lastMin)
                lastMin = arr[i];
            else
                flag = false;
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}