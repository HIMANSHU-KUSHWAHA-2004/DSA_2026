#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>& graph, int st, int node)
{
    vector<int> visited(node + 1, 0);
    queue<int> qu;

    qu.push(st);
    visited[st] = 1;

    while (!qu.empty())
    {
        int temp = qu.front();
        qu.pop();

        cout << temp << " ";

        for (auto i : graph[temp])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                qu.push(i);
            }
        }
    }
}
int main()
{
    int n = 6; // number of nodes

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

    BFS(adj,3,n);
    /*
    1 ---- 2 ---- 5
    |      |
    |      |
    3 ---- 4 ---- 6
    */

}