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

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if ((j == 1) || (j == i))
                    cout << 1 << " ";
                else
                    cout << 0 << " ";
            }

            cout << nl;
        }
    }

    return 0;
}