#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (1)
    {
        int q;
        cin >> q;
        if (q == 0)
            break;

        int n, m;
        cin >> n >> m;

        while (q--)
        {
            int x, y;
            cin >> x >> y;

            if (x == n || y == m)
                cout << "divisa\n";
            else if (x > n && y > m)
                cout << "NE\n";
            else if (x > n && y < m)
                cout << "SE\n";
            else if (x < n && y > m)
                cout << "NO\n";
            else if (x < n && y < m)
                cout << "SO\n";
        }
    }

    return 0;
}