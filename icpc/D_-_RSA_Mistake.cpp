#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

void primeFactors(vector<ll> &v, ll n)
{
    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        v.push_back(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    vector<ll> v;

    primeFactors(v, b);
    primeFactors(v, a);

    map<ll, ll> mp;
    for (auto ele : v)
        mp[ele]++;

    if (v.size() == 2)
    {
        if (v[0] != v[1])
            cout << "full credit" << nl;
        else
            cout << "no credit" << nl;
    }
    else
    {
        if (all_of(mp.begin(), mp.end(), [](pair<ll, ll> a)
                   { return a.second == 1; }))
            cout << "partial credit" << nl;
        else
            cout << "no credit" << nl;
    }

    return 0;
}
