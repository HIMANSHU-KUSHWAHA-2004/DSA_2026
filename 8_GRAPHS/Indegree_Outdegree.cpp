#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V = 6;

    // Adjacency List
    vector<vector<int>> adj = {
        {1, 2}, // 0 -> 1, 2
        {3},    // 1 -> 3
        {3, 4}, // 2 -> 3, 4
        {5},    // 3 -> 5
        {5},    // 4 -> 5
        {}      // 5 -> no edges
    };

    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto node : adj[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    // Indegree
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto k : adj[i])
        {
            indegree[k]++;
        }
    }

    cout << "\nIndegree:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " - " << indegree[i] << endl;
    }

    // Reverse graph
    vector<vector<int>> adj_rev(V);
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            adj_rev[j].push_back(i);
        }
    }

    cout << "\nReverse Adjacency List:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (auto node : adj_rev[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }

    // Outdegree
    vector<int> outdegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        outdegree[i] = adj[i].size();
    }

    cout << "\nOutdegree:\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " - " << outdegree[i] << endl;
    }

    return 0;
}