#include <iostream>
using namespace std;

int checked(int n, int arr[])
{
    int flag = 0, maxT = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                flag++;
                maxT = max(maxT, flag);
            }
        }

        flag = 0;
    }

    return maxT;
}

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

        int flag = checked(n, arr);
        int minOps = flag;
        for (int i = 0; i == flag; i++)
        {
            minOps += 1;
            flag *= 2;
        }

        cout << minOps << endl;
    }

    return 0;
}