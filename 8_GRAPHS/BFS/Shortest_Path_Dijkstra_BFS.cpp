#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, vector<vector<int>>& edges, int src, int dest) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> dist(n, INT_MAX), parent(n);

        for(int i = 0; i < n; i++) parent[i] = i;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

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

        if(dist[dest] == INT_MAX) return {-1};

        vector<int> path;
        int node = dest;

        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);

        reverse(path.begin(), path.end());

        vector<int> ans;
        ans.push_back(dist[dest]);

        for(auto x : path) ans.push_back(x);

        return ans;
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
    int dest = 5;

    vector<int> ans = obj.shortestPath(n, edges, src, dest);

    if(ans.size() == 1 && ans[0] == -1){
        cout << -1 << endl;
    } else {
        cout << "Distance: " << ans[0] << endl;
        cout << "Path: ";
        for(int i = 1; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}