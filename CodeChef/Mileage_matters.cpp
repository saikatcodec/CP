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
        int n, x, y, a, b;
        cin >> n >> x >> y >> a >> b;

        float distP = n * 1.0 / a;
        float distD = n * 1.0 / b;

        float costP = distP * x;
        float costD = distD * y;

        if (costP < costD)
            cout << "PETROL" << nl;
        else if (costD < costP)
            cout << "DIESEL" << nl;
        else
            cout << "ANY" << nl;
    }

    return 0;
}