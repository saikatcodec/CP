#include <iostream>
#include <algorithm>
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

        int maxInd = max_element(arr, arr + n) - arr;
        int len = 0, maxLen = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] == arr[maxInd])
                break;
            else
                len++;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == arr[maxInd])
                len = 0;
            else
            {
                len++;
                maxLen = max(len, maxLen);
            }
        }

        int ans = (maxLen - n / 2) + 1;
        if (ans < 0)
            ans = 0;
        cout << ans << endl;
    }

    return 0;
}