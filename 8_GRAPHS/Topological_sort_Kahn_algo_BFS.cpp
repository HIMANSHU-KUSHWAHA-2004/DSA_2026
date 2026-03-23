#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 🔷 BFS (Kahn's Algorithm)
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        // 🔹 Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }

        // 🔹 Step 2: Calculate indegree of each node
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto nei : adj[i])
            {
                indegree[nei]++;
            }
        }

        // 🔹 Step 3: Push nodes with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // 🔹 Step 4: BFS processing
        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto nei : adj[node])
            {
                indegree[nei]--;

                if (indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        // 🔹 Step 5: Check for cycle
        if (topo.size() != V)
        {
            cout << "Cycle detected! Topo sort not possible.\n";
            return {};
        }

        return topo;
    }
};

int main()
{

    Solution obj;

    // 🔷 Example 1: DAG (valid topo sort)
    int V = 6;
    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}};

    vector<int> result = obj.topoSort(V, edges);

    cout << "Topological Sort: ";
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    // 🔷 Example 2: Graph with cycle
    int V2 = 3;
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {2, 0}};

    vector<int> result2 = obj.topoSort(V2, edges2);

    if (result2.empty())
    {
        cout << "No Topological Order (Cycle exists)" << endl;
    }

    return 0;
}