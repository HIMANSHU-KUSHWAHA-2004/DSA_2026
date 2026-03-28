#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> Adj(n);

        // build graph (undirected)
        for (auto h : roads) {
            Adj[h[0]].push_back({h[1], h[2]});
            Adj[h[1]].push_back({h[0], h[2]});
        }

        // min heap {distance, node}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> Dist(n, LLONG_MAX);
        vector<int> Ways(n, 0);

        int MOD = 1e9 + 7;

        Dist[0] = 0;
        Ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto box = pq.top();
            int dist_nd = box.first;
            int node = box.second;
            pq.pop();

            for (auto o : Adj[node]) {

                int nb = o.first;
                long long wt = o.second;

                // shorter path found
                if (dist_nd + wt < Dist[nb]) {
                    Dist[nb] = dist_nd + wt;
                    Ways[nb] = Ways[node];
                    pq.push({Dist[nb], nb});
                }
                // same shortest path found
                else if (dist_nd + wt == Dist[nb]) {
                    Ways[nb] = (Ways[nb] + Ways[node]) % MOD;
                }
            }
        }

        return Ways[n - 1];
    }
};


// 🔷 MAIN FUNCTION (VS CODE RUN)
int main() {

    Solution obj;

    // 🔥 Example
    int n = 4;

    vector<vector<int>> roads = {
        {0,1,1},
        {0,2,1},
        {1,3,1},
        {2,3,1}
    };

    int result = obj.countPaths(n, roads);

    cout << "Number of shortest paths: " << result << endl;

    return 0;
}