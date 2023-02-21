#include <bits/stdc++.h>
using namespace std;

void sieve(int n, int notPrime[])
{
    notPrime[0] = 1, notPrime[1] = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (notPrime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                notPrime[j] = 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int fNum, sNum, count = 0;
        cin >> fNum >> sNum;

        int notPrime[sNum + 1] = {0};
        sieve(sNum + 1, notPrime);

        for (int i = fNum; i <= sNum; i++)
        {
            if (notPrime[i] == 0)
                count++;
        }

        cout << count << endl;
    }

    return 0;
}