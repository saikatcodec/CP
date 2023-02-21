#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 10; i <= 20; i++)
    {
        bool prime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
            cout << i << " ";
    }

    return 0;
}