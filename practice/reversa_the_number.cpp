#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, rev = 0;
        cin >> n;

        while (n)
        {
            int temp = n % 10;
            rev = rev * 10 + temp;
            n /= 10;
        }

        cout << rev << endl;
    }

    return 0;
}