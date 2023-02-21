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

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        bool flag = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (!(arr[i] < arr[i + 1]))
                flag = true;
        }

        if (flag)
            cout << "NO" << nl;
        else
            cout << "YES" << nl;
    }

    return 0;
}