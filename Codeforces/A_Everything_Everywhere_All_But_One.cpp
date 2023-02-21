#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            sum -= arr[i];
            int div = sum / (n - 1);

            if (sum % (n - 1) == 0 && div == arr[i])
            {
                flag = true;
                break;
            }

            sum += arr[i];
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}