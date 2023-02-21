#include <bits/stdc++.h>
using namespace std;

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

        int nextRound = ceil(n / 5.0) * 5;

        if ((nextRound - n < 3) && (n >= 38))
            cout << nextRound << endl;
        else
            cout << n << endl;
    }

    return 0;
}