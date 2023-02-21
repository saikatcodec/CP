#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int reg[n];
    for (int i = 0; i < n; i++)
    {
        cin >> reg[i];
    }

    sort(reg, reg + n, greater<int>());
    int lossReg = n / 2;

    int ans = 0;
    for (int i = 0; i < lossReg; i++)
    {
        ans += reg[i];
    }

    for (int i = lossReg; i < n; i++)
    {
        ans += (reg[i] / 2);
    }

    cout << ans << nl;

    return 0;
}