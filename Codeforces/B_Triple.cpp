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

        sort(arr, arr + n);
        int value = -1;
        for (int i = 0; i < n - 2; i++)
        {
            if (arr[i] == arr[i + 2])
            {
                value = arr[i];
                break;
            }
        }

        cout << value << endl;
    }

    return 0;
}