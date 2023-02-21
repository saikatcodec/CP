#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long double fact = 1;
        cin >> n;

        for (int i = 2; i <= n; i++)
            fact *= i;

        fixed(cout);
        cout << setprecision(0) << fact << endl;
    }

    return 0;
}