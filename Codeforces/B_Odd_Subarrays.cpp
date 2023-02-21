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
        int n;
        cin >> n;

        int arr[n], ans = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int minVal = arr[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > minVal)
            {
                ans++;
                if (i - 1 >= 0)
                {
                    minVal = arr[i - 1];
                }
            }
            else
                minVal = min(minVal, arr[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}