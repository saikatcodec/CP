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

        for (int num = 2; num <= n; num++)
        {
            int sum = 1;

            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                    sum += i + num / i;
            }

            if (sum == num)
                cout << num << endl;
        }

        cout << endl;
    }

    return 0;
}