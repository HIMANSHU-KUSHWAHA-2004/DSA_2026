#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Prims(int v, vector<vector<pair<int,int>>> &adj, int &totalWeight){
    vector<vector<int>> MST;
    vector<int> Visited(v,0);

    priority_queue<pair<int,pair<int,int>>,
                   vector<pair<int,pair<int,int>>>,
                   greater<pair<int,pair<int,int>>>> pq;

    // {weight, {node, parent}}
    pq.push({0,{0,-1}});
    totalWeight = 0;

    while(!pq.empty()){
        auto box = pq.top();
        pq.pop();

        int weight = box.first;
        int node = box.second.first;
        int parent = box.second.second;

        if(Visited[node]) continue;

        Visited[node] = 1;

        if(parent != -1){
            /*THIS IS JUST BECAUSE IF WE PUSH WITH THIS CONDITON THERE WOULD BE A EXTRA EDGE THAT IS -1 ----> 0 WHICH IS WRONG AND
            THERE IS NOTHING WRONG WITH THE WEIGHT WE CAN PUT IT INSIDEE OR CAN ALSO OUTSIDE SINCE WE STORE 0 AS THE INITIAL WEIGHT*/
            MST.push_back({parent, node});
            totalWeight += weight; // ✅ add weight
        }

        for(auto k : adj[node]){
            int neigh = k.first;
            int wt = k.second;

            if(!Visited[neigh]){
                pq.push({wt, {neigh, node}});
            }
        }
    }
    return MST;
}

int main() {
    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    // Undirected graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    int totalWeight;
    auto ans = Prims(V, adj, totalWeight);

    cout << "MST Edges:\n";
    for(auto e : ans){
        cout << e[0] << " - " << e[1] << endl;
    }

    cout << "Total MST Weight: " << totalWeight << endl;

    return 0;
}