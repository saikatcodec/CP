#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int lcm = (a * b) / __gcd(a, b);

        for (int i = lcm; i <= c; i += lcm)
            cout << i << endl;

        cout << endl;
    }

    return 0;
}