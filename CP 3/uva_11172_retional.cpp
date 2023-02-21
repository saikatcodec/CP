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
        int a, b;
        cin >> a >> b;

        if (a < b)
            cout << "<" << nl;
        else if (a > b)
            cout << ">" << nl;
        else
            cout << "=" << nl;
    }

    return 0;
}