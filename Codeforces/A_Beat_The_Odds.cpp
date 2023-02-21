#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, oddcnt = 0;
        cin >> n;

        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
                oddcnt++;
        }

        int ans = min(oddcnt, n - oddcnt);
        cout << ans << "\n";
    }

    return 0;
}