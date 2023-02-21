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
        int n;
        cin >> n;

        int arr[n];
        if (n & 1)
        {
            for (int i = 0; i < n; i++)
            {
                arr[i] = i + 1;
            }

            for (int i = 0; i < n - 5; i += 2)
            {
                swap(arr[i], arr[i + 1]);
            }
            for (int i = n - 5; i < n - 3; i++)
            {
                swap(arr[i], arr[i + 1]);
            }

            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << nl;
        }
        else
        {
            for (int i = n - 2; i >= 1; i--)
            {
                cout << i << " ";
            }
            cout << n - 1 << " " << n << nl;
        }
    }

    return 0;
}