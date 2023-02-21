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
        int n, m, sum = 0;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            sum += a;
        }

        int ans = sum - m;
        if (ans <= 0)
            cout << "0\n";
        else
            cout << ans << endl;
    }

    return 0;
}