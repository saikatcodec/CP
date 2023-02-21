#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    unordered_map<T, list<T>> gp;

    void dfs_helper(T src, unordered_map<T, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;

        for (auto p : gp[src])
        {
            if (!visited[p])
                dfs_helper(p, visited);
        }
    }

public:
    void addEdges(T x, T y)
    {
        gp[x].push_back(y);
        gp[y].push_back(x);
    }

    void dfs()
    {
        unordered_map<T, bool> visited;
        for (auto p : gp)
        {
            visited[p.first] = false;
        }

        int cnt = 0;

        for (auto p : gp)
        {
            if (!visited[p.first])
            {
                cnt++;
                cout << "Component " << cnt << " --> ";
                dfs_helper(p.first, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    int e;
    cout << "Enter edges number: ";
    cin >> e;

    Graph<int> g;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdges(a, b);
    }

    g.dfs();

    return 0;
}