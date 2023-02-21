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

    void bfs(T st)
    {
        queue<T> q;
        unordered_map<T, bool> visited;

        q.push(st);
        visited[st] = true;

        while (!q.empty())
        {
            T top = q.front();
            q.pop();

            cout << top << " ";
            for (auto ele : l[top])
            {
                if (!visited[ele])
                {
                    q.push(ele);
                    visited[ele] = true;
                }
            }
        }
        cout << endl;
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
    gp.bfs(st);

    return 0;
}