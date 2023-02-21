#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    multiset<long long> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp.insert(a);
    }

    int ans = mp.count(*max_element(mp.begin(), mp.end()));
    cout << ans << "\n";

    return 0;
}