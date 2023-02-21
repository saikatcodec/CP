#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        float root = sqrt(n);
        if (ceil(root) == floor(root))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}