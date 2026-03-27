#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int>>> &adj, int v, int src)
{
    vector<int> Dist(v, INT_MAX);
    Dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Hipo;
    Hipo.push({0, src});

    while (!Hipo.empty()) {
        auto pr = Hipo.top();
        Hipo.pop();

        int node_wt = pr.first;
        int node = pr.second;

        if(node_wt > Dist[node]) continue;

        for (auto l : adj[node]) {
            int neighbour_nd = l.first;
            int neighbour_wt = l.second;

            if (node_wt + neighbour_wt < Dist[neighbour_nd]) {
                Dist[neighbour_nd] = node_wt + neighbour_wt;
                Hipo.push({Dist[neighbour_nd], neighbour_nd});
            }
        }
    }

    return Dist;
}

int main()
{
    int V = 6;
    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    adj[2].push_back({1, 2});
    adj[1].push_back({2, 2});

    adj[1].push_back({3, 1});
    adj[3].push_back({1, 1});

    adj[2].push_back({3, 5});
    adj[3].push_back({2, 5});

    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});

    adj[4].push_back({5, 1});
    adj[5].push_back({4, 1});

    int src = 0;
    vector<int> Boka = Dijkstra(adj, V, src);

    for (auto k : Boka) {
        cout << k << " ";
    }
}