#include <bits/stdc++.h>
using namespace std;

bool BFS(int start, vector<vector<int>> &graph, vector<int> &visited)
{
    queue<pair<int,int>> q; // node , parent
    visited[start] = 1;
    q.push({start,-1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto neighbor : graph[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = 1;
                q.push({neighbor,node});
            }
            else if(neighbor != parent)
            {
                return true; // cycle found
            }
        }
    }

    return false;
}

bool detectCycle(int V, vector<vector<int>> &graph)
{
    vector<int> visited(V,0);

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(BFS(i, graph, visited))
                return true;
        }
    }

    return false;
}

int main()
{
    int V = 4;
    vector<vector<int>> graph(V);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(1);
    graph[1].push_back(3);

    if(detectCycle(V, graph))
        cout << "Cycle Found";
    else
        cout << "No Cycle";

    return 0;
}