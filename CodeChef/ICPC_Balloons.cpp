#include <bits/stdc++.h>
using namespace std;

int bitMask(int num, int pos)
{
    int mask = 1 << (pos - 1);
    return num | mask;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n], mask = 128, count = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            count++;

            if (arr[i] <= 7 && arr[i] >= 1)
            {
                mask = bitMask(mask, arr[i]);
                if (mask == 255)
                    break;
            }
        }

        cout << count << endl;
    }

    return 0;
}