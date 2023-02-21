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
        int w, x, y, z;
        cin >> w >> x >> y >> z;

        int total = w + (x * z);
        total = total - (y * z);

        cout << total << nl;
    }

    return 0;
}