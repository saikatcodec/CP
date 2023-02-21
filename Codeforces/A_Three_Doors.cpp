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
        int x, cnt = 1;
        cin >> x;

        int arr[3];
        for (int i = 0; i < 3; i++)
            cin >> arr[i];

        for (int i = 0; i < 3; i++)
        {
            x = arr[x - 1];
            if (x == 0)
                break;
            cnt++;
        }

        if (cnt == 3)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}