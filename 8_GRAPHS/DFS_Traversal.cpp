#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& graph, int st, vector<int>& visited)
{
    visited[st] = 1;
    cout << st << " ";

    for(int i : graph[st]){
        if(!visited[i]){
            DFS(graph, i, visited);
        }
    }
}

int main()
{
    int n = 6;

    vector<vector<int>> adj(n+1);

    // edges
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[2].push_back(5);
    adj[5].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(6);
    adj[6].push_back(4);

    // printing adjacency list
    for(int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for(int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    vector<int> visited(n+1,0);

    cout << "\nDFS Traversal: ";
    DFS(adj,5,visited);

}