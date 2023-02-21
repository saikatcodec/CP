#include <bits/stdc++.h>
using namespace std;

inline bool inHouse(int val, pair<int, int> house)
{
    if (val >= house.first and val <= house.second)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int s, t, a, b, m, n, appIn = 0, orgIn = 0;
    cin >> s >> t;
    cin >> a >> b;
    cin >> m >> n;

    int apple[m], orange[n];
    for (int i = 0; i < m; i++)
    {
        cin >> apple[i];
        if (inHouse(apple[i] + a, make_pair(s, t)))
            appIn++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> orange[i];
        if (inHouse(orange[i] + b, make_pair(s, t)))
            orgIn++;
    }

    cout << appIn << endl;
    cout << orgIn << endl;

    return 0;
}