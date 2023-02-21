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
        int a[n];
        ll pref[n] = {0};
        int max_data = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            max_data = max(max_data, a[i]);
        }
        pref[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + a[i];
        }
        ll sum = 0;
        int ans = n;
        for (int i = 0; i < n - 1; i++)
        {
            sum = pref[i];
            ll newSum = 0;
            int start = i + 1;
            int seg = i+1;
            bool flag = false;
            for (int j = i + 1; j < n; j++)
            {
                newSum += a[j] * 1LL;
                if (newSum == sum)
                {
                    newSum = 0;
                    seg = max(seg, (j - start + 1));
                    start = j + 1;
                    if(j==n-1){flag = true;}
                }
                else if (newSum > sum)
                {
                    break;
                }
                if (flag)
                    ans = min(seg, ans);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}