#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
typedef long long ll;
ll fact(ll);
ll nCr(ll);

template <class T>
class Graph
{
    unordered_map<T, list<T>> g;

    void dfs(T st, ll &cnt, unordered_map<T, bool> &visited)
    {
        visited[st] = true;
        cnt++;

        for (auto node : g[st])
        {
            if (!visited[node])
            {
                dfs(node, cnt, visited);
            }
        }
    }

public:
    void addEdges(T x, T y)
    {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    ll countryNum()
    {
        ll ans = 0;
        unordered_map<T, bool> visited;
        for (auto node_pair : g)
        {
            visited[node_pair.first] = false;
        }

        for (auto node_pair : g)
        {
            T node = node_pair.first;
            if (!visited[node])
            {
                ll val = 0;
                dfs(node, val, visited);
                if (val > 1)
                    ans += nCr(val);
            }
        }

        return ans;
    }
};

ll nCr(ll n)
{
    ll r = 2;
    ll res = 1;

    if (r > n - r)
        r = n - r;

    for (ll i = 0; i < r; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n, p;
    cin >> n >> p;

    Graph<ll> gp;

    for (ll i = 0; i < n; i++)
    {
        gp.addEdges(i, i);
    }

    for (ll i = 0; i < p; i++)
    {
        ll a, b;
        cin >> a >> b;

        gp.addEdges(a, b);
    }

    ll res = gp.countryNum();
    cout << (nCr(n) - res) << nl;

    return 0;
}