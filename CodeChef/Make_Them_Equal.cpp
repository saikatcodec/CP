#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int odd = 0, even = 0, minimum;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        if (odd % 2 == 0)
            cout << min(odd / 2, even) << endl;
        else
            cout << even << endl;
    }

    return 0;
}