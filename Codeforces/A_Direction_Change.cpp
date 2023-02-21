#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, ans;
        cin >> n >> m;

        if (n == 1 && m == 1)
            ans = 0;
        else if ((n == 1 && m == 2) || (n == 2 && m == 1))
            ans = 1;
        else if (n == 1 || m == 1)
            ans = -1;
        else
        {
            ans = 2 * (min(n, m) - 1);
            int dif = abs(n - m);
            ans += dif * 2;
            if (dif & 1)
                ans--;
        }

        cout << ans << endl;
    }

    return 0;
}