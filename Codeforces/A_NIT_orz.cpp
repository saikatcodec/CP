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
        int n, z;
        cin >> n >> z;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = arr[i] | z;
        }

        sort(res.begin(), res.end());
        cout << res[n - 1] << nl;
    }

    return 0;
}