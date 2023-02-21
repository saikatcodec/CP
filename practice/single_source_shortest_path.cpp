#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    unordered_map<T, list<T>> l;

public:
    void addEdges(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void findShortestDist(T st)
    {
        queue<T> q;
        unordered_map<T, int> dist;

        for (auto node_pair : l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(st);
        dist[st] = 0;

        while (!q.empty())
        {
            T top = q.front();
            q.pop();

            for (T nbr : l[top])
            {
                if (dist[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    dist[nbr] = dist[top] + 1;
                }
            }
        }

        for (auto node_pair : l)
        {
            cout << "Distance from the source of " << node_pair.first << " is " << dist[node_pair.first] << endl;
        }
    }
};

int main()
{
    Graph<int> gp;
    int e;

    cout << "Enter vertex number: ";
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        gp.addEdges(x, y);
    }

    int st;
    cout << "Give the starting point: ";
    cin >> st;

    cout << "Print graph using bfs" << endl;
    gp.findShortestDist(st);

    return 0;
}