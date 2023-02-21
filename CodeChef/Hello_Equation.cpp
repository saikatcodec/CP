#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

void solve(int x)
{
    for (int i = 1; i * i <= x; i++)
    {
        if (((x - 2 * i) % (i + 2) == 0) && (x != 2 * i))
        {
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
}

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
        solve(x);
    }

    return 0;
}