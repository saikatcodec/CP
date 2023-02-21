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

        set<int> distinct;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            distinct.insert(a);
        }

        if ((n & 1) ^ (distinct.size() & 1))
            cout << distinct.size() - 1 << endl;
        else
            cout << distinct.size() << endl;
    }

    return 0;
}