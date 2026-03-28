#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, int dest,
             vector<vector<pair<int,int>>>& adj,
             vector<long long>& dist,
             vector<int>& path,
             vector<vector<int>>& allPaths) {

        path.push_back(node);

        if(node == dest){
            allPaths.push_back(path);
        }
        else {
            for(auto &nbr : adj[node]){
                int next = nbr.first;
                int wt = nbr.second;

                // 🔥 only shortest path edges
                if(dist[node] + wt == dist[next]){
                    dfs(next, dest, adj, dist, path, allPaths);
                }
            }
        }

        path.pop_back();
    }

    void solve(int n, vector<vector<int>>& roads, int src, int dest) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // 🔷 DIJKSTRA
        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

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

        // 🔷 DFS to get ALL shortest paths
        vector<vector<int>> allPaths;
        vector<int> path;

        dfs(src, dest, adj, dist, path, allPaths);

        // 🔷 OUTPUT
        cout << "Shortest Distance: " << dist[dest] << endl;

        cout << "All Shortest Paths:\n";
        for(auto &p : allPaths){
            for(auto x : p) cout << x << " ";
            cout << endl;
        }
    }
};


// 🔷 MAIN
int main() {

    Solution obj;

    int n = 5;

    vector<vector<int>> roads = {
        {0,1,1},
        {0,2,1},
        {0,3,1},
        {1,4,1},
        {2,4,1},
        {3,4,1}
    };

    int src = 0;
    int dest = 4;

    obj.solve(n, roads, src, dest);

    return 0;
}