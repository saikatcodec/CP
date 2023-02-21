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
        int a, b, c;
        cin >> a >> b >> c;

        if (a == b && b == c && a == c)
            cout << "YES\n";
        else if (a == b && b < c)
            cout << "YES\n";
        else if (a == c && a < b)
            cout << "YES\n";
        else if (c == b && b < a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}