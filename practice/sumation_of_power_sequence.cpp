#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, k;
        cin >> x >> k;

        int sum = 1, power = 1;
        for (int i = 1; i <= k; i++)
        {
            power *= x;
            sum += power;
        }

        cout << "Result = " << sum << endl;
    }

    return 0;
}