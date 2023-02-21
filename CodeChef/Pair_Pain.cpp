#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long arr[n];
        long long c1 = 0, c2 = 0;
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] == 1)
                c1++;
            if (arr[i] == 2)
                c2++;
        }

        long long ans = c1 * (n - c1) + c1 * (c1 - 1) / 2 + c2 * (c2 - 1) / 2;
        cout << ans << endl;
    }

    return 0;
}