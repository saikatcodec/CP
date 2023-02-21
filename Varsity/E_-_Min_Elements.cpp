#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int x = p[0], cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (x >= p[i])
            cnt++;
        x = min(x, p[i]);
    }

    cout << cnt << nl;

    return 0;
}