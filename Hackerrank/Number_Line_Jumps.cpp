#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    if ((x1 > x2 && v1 > v2) || (x2 > x1 && v2 > v1))
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}