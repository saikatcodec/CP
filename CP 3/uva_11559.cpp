#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    long long n, b, h, w;

    while (scanf("%lld %lld %lld %lld", &n, &b, &h, &w) != EOF)
    {
        vector<long long> res;

        while (h--)
        {
            long long p, beds[w];
            cin >> p;

            for (int i = 0; i < w; i++)
            {
                cin >> beds[i];

                if (beds[i] >= n)
                    res.push_back(n * p);
            }
        }

        if (res.size() == 0)
            printf("stay home\n");
        else
        {
            long long minVal = *min_element(res.begin(), res.end());
            if (minVal > b)
                printf("stay home\n");
            else
                printf("%lld\n", minVal);
        }
    }

    return 0;
}