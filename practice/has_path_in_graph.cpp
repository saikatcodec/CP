#include <bits/stdc++.h>
using namespace std;

bool has_path(int **edges, int n, int st, int ed, bool *visited)
{
    visited[st] = true;
    if (edges[st][ed] == 1)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (st == i)
            continue;
        if (edges[st][i] == 1 && !visited[i])
        {
            if (i == ed)
                return true;
            bool _ = has_path(edges, n, i, ed, visited);
        }
    }

    if (visited[n - 1] == true)
    {
        return false;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int st, ed;
    cin >> st >> ed;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    bool path = has_path(edges, n, st, ed, visited);
    if (path)
        cout << "Path exits" << endl;
    else
        cout << "Path does not exits" << endl;

    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}