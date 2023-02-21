#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, sum = 0;
        cin >> n;

        string s;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                sum += i;
            else if (s[i] == 'R')
                sum += (n - i - 1);
        }

        ll middle = n / 2LL;
        vector<ll> v;
        for (int i = 0; i < n; i++)
        {
            if (i < middle && s[i] == 'L')
                v.push_back(n - i - 1 - i);
            else if (i >= middle && s[i] == 'R')
                v.push_back(i - (n - i - 1));
        }

        sort(v.begin(), v.end(), greater<ll>());
        ll size = v.size();
        for (int i = 0; i < n; i++)
        {
            if (size)
            {
                sum += v[i];
                size--;
            }
            cout << sum << " ";
        }
        cout << nl;
    }

    return 0;
}