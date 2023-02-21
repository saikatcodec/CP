/**
 * @file graph_implement.cpp
 * @author Joy Acharjee
 * @brief Input graph and print the graph in form of DFS
 * @version 0.1
 * @date 2022-09-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int st, bool *visited)
{
    cout << st << endl;
    visited[st] = true;

    for (int i = 0; i < n; i++)
    {
        if (st == i)
            continue;
        if (edges[st][i] == 1)
        {
            if (visited[i])
                continue;
            print(edges, n, i, visited);
        }
    }
}

void print_BFS(int **edges, int n, int st)
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
    // Input vertices number and edges number
    cin >> n >> e;

    // Set adjacency matrix
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // Input edges of graph
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // A node visited or not
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // Print graph value using DFS
    cout << "Print the graph using DFS:\n";
    print(edges, n, 0, visited);

    cout << "Print the graph using BFS:\n";
    print_BFS(edges, n, 0);

    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}