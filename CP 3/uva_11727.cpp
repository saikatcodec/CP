#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t, n;
    cin >> t;

    n = t;

    while (t--)
    {
        int arr[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + 3);
        cout << "Case " << (n - t) << ": " << arr[1] << nl;
    }

    return 0;
}