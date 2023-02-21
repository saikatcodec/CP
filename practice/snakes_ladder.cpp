#include <bits/stdc++.h>
using namespace std;

template <class T>
class Graph
{
    unordered_map<T, list<T>> g;

public:
    void addEdges(T x, T y)
    {
        g[x].push_back(y);
    }

    int getDist(T st, T dest)
    {
        queue<T> q;
        unordered_map<T, int> dist;
        unordered_map<T, T> parent;

        for (auto node_pair : g)
        {
            dist[node_pair.first] = INT_MAX;
        }

        q.push(st);
        dist[st] = 0;
        parent[st] = st;

        while (!q.empty())
        {
            T front_node = q.front();
            q.pop();

            for (auto node : g[front_node])
            {
                if (dist[node] == INT_MAX)
                {
                    q.push(node);
                    dist[node] = dist[front_node] + 1;
                    parent[node] = front_node;
                }
            }
        }

        cout << "Paths are: ";
        T temp = dest;
        while (temp != st)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << st << endl;

        return dist[dest];
    }
};

int main()
{
    Graph<int> gp;

    int board[37] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[17] = -13;
    board[18] = 11;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    for (int i = 0; i <= 36; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice;
            j += board[j];

            if (j <= 36)
                gp.addEdges(i, j);
        }
    }
    gp.addEdges(36, 36);
    int ans = gp.getDist(0, 36);
    cout << "Minimum dice throws: " << ans << endl;

    return 0;
}