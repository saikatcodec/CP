#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, n;
        cin >> x >> n;

        if (x <= n)
        {
            for (int i = x; i <= n; i += x)
            {
                cout << i << endl;
            }
        }
        else
            cout << "Invalid!" << endl;

        cout << endl;
    }

    return 0;
}