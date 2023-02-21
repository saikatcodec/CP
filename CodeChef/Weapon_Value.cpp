#include <iostream>
#include <cstring>
using namespace std;

int maxNum(int arr[])
{
    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 != 0)
            sum += (arr[i] % 2);
    }

    return sum;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string strs[n];
        for (int i = 0; i < n; i++)
            cin >> strs[i];

        int arr[10];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (strs[i][j] == '1')
                    arr[j]++;
            }
        }

        cout << maxNum(arr) << endl;
    }

    return 0;
}