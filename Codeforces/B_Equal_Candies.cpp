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

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int min = *min_element(arr, arr + n);
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (min < arr[i])
                sum += (arr[i] - min);
        }

        cout << sum << endl;
    }

    return 0;
}