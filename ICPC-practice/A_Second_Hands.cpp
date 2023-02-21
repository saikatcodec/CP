#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    freopen("Error.txt", "w", stdout);

    int tr = t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        bool flag = true;
        int cnt = 0;
        for (int ele : v)
        {
            if (mp[ele] > 2)
            {
                flag = false;
                break;
            }
            else
                cnt++;
        }

        if (flag && ceil(cnt / 2.0) <= k)
        {
            if (t == 0)
                cout << "Case #" << (tr - t) << ": YES";
            else
                cout << "Case #" << (tr - t) << ": YES" << nl;
        }
        else
            cout << "Case #" << (tr - t) << ": NO" << nl;
    }

    return 0;
}