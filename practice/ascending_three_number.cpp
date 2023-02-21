#include <bits/stdc++.h>
using namespace std;

void ordered(int n[])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = i; j < 3; j++)
        {
            if (n[i] > n[j])
                swap(n[i], n[j]);
        }
    }
}

int main()
{
    int t, tl;
    cin >> t;
    tl = t;

    while (t--)
    {
        int n[3];
        for (int i = 0; i < 3; i++)
            cin >> n[i];

        ordered(n);

        cout << "Case " << tl - t << ":";
        for (int i = 0; i < 3; i++)
            cout << " " << n[i];

        cout << endl;
    }

    return 0;
}