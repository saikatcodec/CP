#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, remain = 0, ans = 0;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        remain = (remain - a) + b;
        ans = max(ans, remain);
    }

    cout << ans << "\n";

    return 0;
}