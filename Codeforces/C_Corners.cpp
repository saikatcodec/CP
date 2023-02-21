#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define nll cout << "\n"
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, minV = INT_MAX;
        cin >> n >> m;

        string s;
        int arr[n][m], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = s[j] - '0';
                sum += arr[i][j];
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                int cnt = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
                if (cnt == 0)
                    continue;
                minV = min(minV, max(1, cnt - 1));
            }
        }

        if (sum == 0)
            cout << "0" << nl;
        else
            cout << 1 + sum - minV << nl;
    }
    return 0;
}