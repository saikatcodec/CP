#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int sum = 1;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                sum += i + n / i;
        }

        if (sum == n)
            cout << "YES, " << n << " is a perfect number!" << endl;
        else
            cout << "NO, " << n << " is not a perfect number!" << endl;
    }

    return 0;
}