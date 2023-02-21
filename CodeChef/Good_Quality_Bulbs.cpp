#include <iostream>
using namespace std;

int sumA(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
        sum += arr[i];

    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        int arr[n - 1];
        for (int i = 0; i < n - 1; i++)
            cin >> arr[i];

        int sum = sumA(n, arr);
        int ans = (x * n) - sum;
        
        if (ans <= 0)
            ans = 0;

        cout << ans << endl;
    }

    return 0;
}