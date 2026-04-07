#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // 🔷 Relax edges V-1 times
        for(int i = 0; i < V - 1; i++){
            for(auto &e : edges){
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // 🔷 Check negative cycle
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                cout << "❌ Negative Cycle Detected!\n";
                return {-1};
            }
        }

        return dist;
    }
};


// 🔷 MAIN FUNCTION
int main() {

    Solution obj;

    // ============================
    // 🔥 EXAMPLE 1: NORMAL GRAPH
    // ============================
    cout << "Example 1: Normal Graph\n";

    int V1 = 3;
    vector<vector<int>> edges1 = {
        {0,1,4},
        {1,2,-3},
        {0,2,5}
    };

    int src1 = 0;

    vector<int> res1 = obj.bellmanFord(V1, edges1, src1);

    if(res1[0] != -1){
        cout << "Shortest distances:\n";
        for(int i = 0; i < V1; i++){
            cout << "Node " << i << " -> " << res1[i] << endl;
        }
    }

    cout << "\n";


    // ============================
    // 🔥 EXAMPLE 2: NEGATIVE CYCLE
    // ============================
    cout << "Example 2: Negative Cycle Graph\n";

    int V2 = 3;
    vector<vector<int>> edges2 = {
        {0,1,1},
        {1,2,-2},
        {2,0,-2}
    };

    int src2 = 0;

    vector<int> res2 = obj.bellmanFord(V2, edges2, src2);

    if(res2[0] != -1){
        cout << "Shortest distances:\n";
        for(int i = 0; i < V2; i++){
            cout << "Node " << i << " -> " << res2[i] << endl;
        }
    }

    return 0;
}