#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;

void print_queue(priority_queue<ll, vector<ll>, greater<ll>> qu)
{
    while (!qu.empty())
    {
        cout << qu.top() << " ";
        qu.pop();
    }

    cout << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;

        priority_queue<ll, vector<ll>, greater<ll>> qu;

        ll a;
        for (ll i = 0; i < n; i++)
        {
            cin >> a;
            qu.push(a);
        }

        ll op = 0, curent, x_or;
        while (op < y)
        {
            curent = qu.top();
            x_or = curent ^ x;
            op++;
            qu.pop();
            qu.push(x_or);
            if (x_or <= curent)
                break;
        }

        y -= op;

        if (y & 1)
        {
            curent = qu.top();
            qu.pop();
            qu.push(curent ^ x);
        }

        print_queue(qu);
    }

    return 0;
}