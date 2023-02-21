#include <bits/stdc++.h>
using namespace std;

void print_DFS(int **edges, int n, int st, bool *visited)
{
    cout << st << endl;
    visited[st] = true;

    for (int i = 0; i < n; i++)
    {
        if (st == i)
            continue;
        if (edges[st][i] == 1 && !visited[i])
            print_DFS(edges, n, i, visited);
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            print_DFS(edges, n, i, visited);
    }

    delete[] visited;
}

void print_BFS(int **edges, int n, int st, bool *visited)
{
    queue<int> qu;
    qu.push(st);

    visited[st] = true;
    while (!qu.empty())
    {
        int crnt = qu.front();
        qu.pop();
        cout << crnt << endl;

        for (int i = 0; i < n; i++)
        {
            if (edges[crnt][i] == 1 && !visited[i])
            {
                qu.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            print_BFS(edges, n, i, visited);
    }

    delete[] visited;
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
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "Print graph using DFS\n";
    DFS(edges, n);

    cout << "Print graph using BFS\n";
    BFS(edges, n);

    delete[] visited;
    for (int i = 0; i < n; i++)
        delete[] edges[i];

    delete[] edges;

    return 0;
}