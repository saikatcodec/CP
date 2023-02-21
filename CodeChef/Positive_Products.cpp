#include <iostream>
#include <cstring>
using namespace std;

void countPosNeg(long long n, long long count[], long long arr[])
{
    for (long long i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            count[0]++;
        else if (arr[i] > 0)
            count[1]++;
    }
}

long long findMax(long long n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return ((n - 1) + findMax(n - 1));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long arr[n];
        for (long long i = 0; i < n; i++)
            cin >> arr[i];

        long long count[2];
        memset(count, 0, sizeof(count));
        countPosNeg(n, count, arr);

        long long sum = 0;
        for (int i = 0; i < 2; i++)
        {
            if (count[i] != 0)
                sum += findMax(count[i]);
        }

        cout << sum << endl;
    }

    return 0;
}