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
        int x, y, z;
        cin >> x >> y >> z;

        int total = (5 * x) + (10 * y);
        cout << total / z << "\n";
    }

    return 0;
}