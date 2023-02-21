#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdges(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printGraph()
    {
        for (auto p : l)
        {
            cout << "Adjacency List of " << p.first << ": " ;
            for (auto ele : p.second)
                cout << ele << " ";
            cout << endl;
        }
    }
};

int main()
{
    Graph<char> gp;

    gp.addEdges('A', 'B');
    gp.addEdges('B', 'C');
    gp.addEdges('C', 'A');

    gp.printGraph();

    return 0;
}