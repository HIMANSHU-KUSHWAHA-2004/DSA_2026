#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔷 Main Dijkstra Function
    pair<vector<vector<int>>, vector<int>> shortestPath(int n, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(n);

        // 🔷 Build graph
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n, INT_MAX), parent(n);

        for(int i = 0; i < n; i++) parent[i] = i;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        // 🔷 Dijkstra
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if(wt > dist[node]) continue;

            for(auto &x : adj[node]){
                int v = x.first;
                int w = x.second;

                if(wt + w < dist[v]){
                    dist[v] = wt + w;
                    parent[v] = node;
                    pq.push({dist[v], v});
                }
            }
        }

        // 🔷 Get all paths
        vector<vector<int>> allPaths = getAllPaths(n, parent);

        return {allPaths, dist};
    }

    // 🔷 Build path for every node
    vector<vector<int>> getAllPaths(int V, vector<int> &parent){
        vector<vector<int>> allPaths(V);

        for(int i = 0; i < V; i++){
            vector<int> path;
            int node = i;

            while(parent[node] != node){
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(node);

            reverse(path.begin(), path.end());

            allPaths[i] = path;
        }

        return allPaths;
    }
};

int main() {

    Solution obj;

    int n = 6;

    vector<vector<int>> edges = {
        {0,1,4},
        {0,2,1},
        {2,1,2},
        {1,3,1},
        {2,3,5},
        {3,4,3},
        {4,5,1}
    };

    int src = 0;

    auto result = obj.shortestPath(n, edges, src);

    vector<vector<int>> allPaths = result.first;
    vector<int> dist = result.second;

    cout << "All shortest paths from source " << src << ":\n\n";

    for(int i = 0; i < n; i++){

        if(dist[i] == INT_MAX){
            cout << "Node " << i << " → unreachable\n";
            continue;
        }

        cout << "Node " << i << "  Distance = " << dist[i] << " , Path = ";

        for(auto x : allPaths[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}