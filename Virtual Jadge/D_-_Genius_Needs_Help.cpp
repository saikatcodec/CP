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

    int f = t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;

        if (a.size() > b.size())
            swap(a, b);

        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        ll n1 = a.size();
        ll n2 = b.size();
        ll carry = 0;

        for (ll i = 0; i < n1; i++)
        {
            ll sum = (a[i] - '0') + (b[i] - '0') + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        for (ll i = n1; i < n2; i++)
        {
            ll sum = (b[i] - '0') + carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            ans.push_back(carry + '0');

        reverse(ans.begin(), ans.end());

        cout << "Case #" << f - t << ": " << ans << endl;
    }

    return 0;
}