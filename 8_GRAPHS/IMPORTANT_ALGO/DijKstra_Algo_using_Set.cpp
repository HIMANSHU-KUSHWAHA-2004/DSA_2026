#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<vector<pair<int, int>>> &adj, int v, int src)
{
    vector<int> Dist(v, INT_MAX);
    Dist[src] = 0;

    set<pair<int,int>> Hipo;
    Hipo.insert({0, src});

    while(!Hipo.empty()){
        auto it = *(Hipo.begin());
        Hipo.erase(Hipo.begin());

        int node = it.second;
        int node_wt = it.first;

        for(auto g : adj[node]){
            int neighbour_node = g.first;
            int neighbour_wt = g.second;

            if(node_wt + neighbour_wt < Dist[neighbour_node]){
                if(Dist[neighbour_node] != INT_MAX){
                    Hipo.erase({Dist[neighbour_node], neighbour_node});
                }
                Dist[neighbour_node] = node_wt + neighbour_wt;
                Hipo.insert({Dist[neighbour_node], neighbour_node});
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