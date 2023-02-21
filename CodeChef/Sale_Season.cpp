#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;

        if (x <= 100)
            x -= 0;
        else if (x <= 1000)
            x -= 25;
        else if (x <= 5000)
            x -= 100;
        else
            x -= 500;

        cout << x << nl;
    }

    return 0;
}