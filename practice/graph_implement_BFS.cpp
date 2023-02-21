/**
 * @file graph_implement_BFS.cpp
 * @author Joy Acharjee
 * @brief Print using BFS
 * @version 0.1
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int st)
{
    queue<int> qu;

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    qu.push(st);
    visited[st] = true;

    while (!qu.empty())
    {
        int current = qu.front();
        qu.pop();
        cout << current << endl;

        for (int i = 0; i < n; i++)
        {
            if (edges[current][i] == 1 && !visited[i])
            {
                qu.push(i);
                visited[i] = true;
            }
        }
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

    // Print the graph
    queue<int> qu;
    cout << "Print the graph\n";
    print(edges, n, 0);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}