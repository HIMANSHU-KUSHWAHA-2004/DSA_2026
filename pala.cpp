#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔷 DFS to collect all shortest paths
    void dfs(int node, int target,
             vector<vector<pair<int,int>>>& adj,
             vector<long long>& dist,
             vector<int>& path,
             vector<vector<int>>& allPaths) {

        path.push_back(node);

        if(node == target){
            allPaths.push_back(path);
        }
        else {
            for(auto &nbr : adj[node]){
                int next = nbr.first;
                int wt = nbr.second;

                // 🔥 only follow shortest path edges
                if(dist[node] + wt == dist[next]){
                    dfs(next, target, adj, dist, path, allPaths);
                }
            }
        }

        path.pop_back();
    }


    vector<vector<int>> getAllPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        // build graph
        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // 🔷 Step 1: Dijkstra
        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto box = pq.top();
            int d = box.first;
            int node = box.second;
            pq.pop();

            for(auto &nbr : adj[node]){
                int next = nbr.first;
                long long wt = nbr.second;

                if(d + wt < dist[next]){
                    dist[next] = d + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        // 🔷 Step 2: DFS to collect paths
        vector<vector<int>> allPaths;
        vector<int> path;

        dfs(0, n-1, adj, dist, path, allPaths);

        return allPaths;
    }
};


// 🔷 MAIN
int main() {

    Solution obj;

    int n = 4;

    vector<vector<int>> roads = {
        {0,1,1},
        {0,2,1},
        {1,3,1},
        {2,3,1}
    };

    vector<vector<int>> paths = obj.getAllPaths(n, roads);

    cout << "All shortest paths:\n";

    for(auto &p : paths){
        for(auto x : p) cout << x << " ";
        cout << endl;
    }

    return 0;
}