#include <bits/stdc++.h>
using namespace std;

void get_path(int **edges, int n, int st, int ed, bool *visited, bool &has_path, vector<int> &path)
{
    path.push_back(st);
    visited[st] = true;

    for (int i = 0; i < n; i++)
    {
        if (st == i)
            continue;
        if (edges[st][i] = 1 && !visited[i])
        {
            if (i == ed)
            {
                has_path = true;
                return;
            }
            get_path(edges, n, i, ed, visited, has_path, path);
        }
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

    bool has_path = false;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<int> path;
    get_path(edges, n, st, ed, visited, has_path, path);

    if (has_path)
    {
        for (int ele : path)
            cout << ele << endl;
    }
    else
        cout << "No path exits" << endl;

    return 0;
}