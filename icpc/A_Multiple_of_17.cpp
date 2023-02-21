#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        ll n;
        cin >> n;

        if (n == 0)
            break;

        ll drop = n / 10;
        ll last = n % 10;

        if (abs(drop - (5 * last)) % 17 == 0)
            cout << "1" << nl;
        else
            cout << "0" << nl;
    }

    return 0;
}