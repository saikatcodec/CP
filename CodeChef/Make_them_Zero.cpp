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

        int arr[n], bit[30] = {0};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            for (int j = 0; j < 30; j++)
            {
                if ((1 << j) & arr[i])
                    bit[j]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < 30; i++)
            ans += (bit[i] > 0);

        cout << ans << "\n";
    }

    return 0;
}