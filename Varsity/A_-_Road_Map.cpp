#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string stat[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stat[i];
    }

    map<string, int> stop;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        stop[str] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (stop[stat[i]] == 1)
            cout << "Yes" << nl;
        else
            cout << "No" << nl;
    }

    return 0;
}