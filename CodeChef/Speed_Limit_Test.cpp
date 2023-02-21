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
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        float spa = a / (x * 1.0);
        float spb = b / (y * 1.0);

        if (spa > spb)
            cout << "Alice" << nl;
        else if (spa < spb)
            cout << "Bob" << nl;
        else
            cout << "Equal" << nl;
    }

    return 0;
}