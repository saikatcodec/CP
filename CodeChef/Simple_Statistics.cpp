#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        int least = n - 2 * k, sum = 0;
        float avg;

        for (int i = k; i < k + least; i++)
            sum += arr[i];

        avg = (sum * 1.0) / least;
        cout.precision(6);
        cout << fixed << avg << endl;
    }

    return 0;
}