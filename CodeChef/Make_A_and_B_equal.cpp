#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

bool isDivisible(int a, int b)
{
    if (ceil(a * 1.0 / b) == floor(a * 1.0 / b))
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int maxV = max(a, b);
        int minV = min(a, b);

        if (isDivisible(maxV, minV))
        {
            int div = maxV / minV;
            if (ceil(log2(div)) == floor(log2(div)))
                cout << "YES" << nl;
            else
                cout << "NO" << nl;
        }
        else
            cout << "NO" << nl;
    }

    return 0;
}