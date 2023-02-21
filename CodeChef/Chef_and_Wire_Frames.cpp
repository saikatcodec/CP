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
        int n, w, p;
        cin >> n >> w >> p;

        int ans = 2 * (n + w) * p;
        cout << ans << nl;
    }

    return 0;
}