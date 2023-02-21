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
        int a[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
        }

        int count = 0;
        for (int i = 1; i < 4; i++)
        {
            if (a[0] < a[i])
                count++;
        }

        cout << count << endl;
    }

    return 0;
}