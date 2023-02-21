#include <iostream>
using namespace std;

int sumOfArr(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, v, sum;
        cin >> n >> k >> v;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sum = sumOfArr(n, arr);

        int value = ((v * (n + k)) - sum);
        int ans = value / k;
        if (ans <= 0 || value % k != 0)
            ans = -1;

        cout << ans << endl;
    }

    return 0;
}