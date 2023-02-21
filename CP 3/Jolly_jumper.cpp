#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    int n;
    vector<int> arr;

    while (scanf("%d", &n) != EOF)
    {
        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            int dif = abs(arr[i] - arr[i + 1]);
            if ((dif >= 1) && (dif <= n - 1))
                flag &= true;
            else
                flag &= false;
        }

        if (flag)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";

        return 0;
    }
}