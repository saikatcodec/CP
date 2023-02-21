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

        int arr[n - 1], sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        int maxV = *max_element(arr, arr + n - 1);
        cout << sum + maxV << nl;
    }

    return 0;
}