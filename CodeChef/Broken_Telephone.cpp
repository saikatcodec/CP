#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int lastIndex = 0, misHeard = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] != arr[i + 1])
            {
                misHeard += 2;
                if (lastIndex == 1)
                    misHeard--;

                lastIndex = 1;
            }
            else
                lastIndex = 0;
        }

        cout << misHeard << endl;
    }

    return 0;
}