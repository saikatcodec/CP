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
        ll n, x, p;
        cin >> n >> x >> p;

        ll score = (3 * x) + ((-1) * (n - x));

        if (p > score)
            cout << "FAIL" << nl;
        else
            cout << "PASS" << nl;
    }

    return 0;
}