#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (n % 2 == 0)
            cout << "Yes\n";
        else
        {
            if (k == 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}