#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n], zero_count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 0)
                zero_count++;
        }

        int dup = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    dup++;
                    break;
                }
            }
        }

        if (zero_count > 0)
            cout << n - zero_count << endl;
        else if (dup > 0)
            cout << n << endl;
        else
            cout << n + 1 << endl;
    }

    return 0;
}