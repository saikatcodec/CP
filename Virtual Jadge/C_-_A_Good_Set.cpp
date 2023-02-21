#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int ans = 1;
        cout << ans << " ";

        for (int i = 1; i < n; i++)
        {
            ans += 2;
            cout << ans << " ";
        }

        cout << endl;
    }

    return 0;
}