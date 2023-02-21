#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int con = 2 * n - 1;
        for (int i = 0; i < con; i++)
        {
            for (int j = 0, k = con - i; j <= i && k > 0; ((i < n) ? j++ : k--))
                cout << m << " ";

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}