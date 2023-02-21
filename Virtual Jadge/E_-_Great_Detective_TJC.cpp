#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        set<int> even;
        set<int> odd;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x & 1)
                odd.insert(x);
            else
                even.insert(x);
        }
        bool ok = 0;
        for (auto it : odd)
        {
            if (even.find(it - 1) != even.end())
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}