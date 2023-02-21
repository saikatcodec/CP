#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (k == 1)
        {
            if (n & 1)
                cout << "ODD\n";
            else
                cout << "EVEN\n";
        }
        else if (k == 2)
            cout << "ODD\n";
        else
            cout << "EVEN\n";
    }

    return 0;
}