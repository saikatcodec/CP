#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << "Vertex " << i << "-> ";
            for (auto ele : l[i])
            {
                cout << ele << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int v, e;
    cin >> v >> e;

    Graph gp(v);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        gp.addEdge(x, y);
    }

    gp.print();

    return 0;
}