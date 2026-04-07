#include <bits/stdc++.h>
using namespace std;

class DSU{
private:
    vector<int> Size;
    vector<int> Parent;
public:
    DSU(int n){
        Size.resize(n,1);
        Parent.resize(n);
        for(int i=0;i<n;i++) Parent[i]=i;
    }

    int Find(int node){
        if(node == Parent[node]) return node;
        return Parent[node] = Find(Parent[node]);
    }

    void Union(int u,int v){
        int pu = Find(u);
        int pv = Find(v);

        if(pu == pv) return;

        if(Size[pu] > Size[pv]){
            Parent[pv] = pu;
            Size[pu] += Size[pv];
        }
        else{
            Parent[pu] = pv;
            Size[pv] += Size[pu];
        }
    }
};

vector<vector<int>> mst;
class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj;

        for(auto e : edges){
            adj.push_back({e[2], e[0], e[1]}); // {wt,u,v}
        }

        sort(adj.begin(), adj.end());

        DSU dsu(V);

        int sum = 0;

        for(auto e : adj){
            int wt = e[0];
            int u = e[1];
            int v = e[2];

            if(dsu.Find(u) != dsu.Find(v)){
                sum += wt;
                dsu.Union(u,v);
                mst.push_back({u,v});
            }
        }

        return sum;
    }
};

int main(){
    int V = 5;

    vector<vector<int>> edges = {
        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7}
    };

    Solution obj;

    int ans = obj.spanningTree(V, edges);

    cout << "MST Weight: " << ans << endl;
    for(auto g : mst){
        cout << g[0] << "--"<< g[1] << endl;
    }
    return 0;
}













