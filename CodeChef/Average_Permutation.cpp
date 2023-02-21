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
        int n;
        cin >> n;

        vector<int> oV, eV;

        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                oV.push_back(i);
            else
                eV.push_back(i);
        }

        reverse(eV.begin(), eV.end());

        for (auto ele : eV)
            cout << ele << " ";
        for (auto ele : oV)
            cout << ele << " ";

        cout << nl;
    }

    return 0;
}