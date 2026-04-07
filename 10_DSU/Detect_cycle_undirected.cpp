#include<bits\stdc++.h>
using namespace std;
class DSU{
    private:
        vector<int> Size;
        vector<int> Parent;
    public:
        DSU(int no_of_nodes){
            Size.resize(no_of_nodes+1,1);
            Parent.resize(no_of_nodes+1);
            for(int i = 1;i<=no_of_nodes;i++){
                Parent[i] = i;
            }
        }
        int Find(int node){
            if(node == Parent[node]){
                return node;
            }
            return Parent[node] = Find(Parent[node]);
        }
        void Union(int u,int v){
            int pu = Find(u);
            int pv = Find(v);
            if(pu == pv){
                return;
            }
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
int main() {
    int n = 5;

    vector<vector<int>> edges;

    // Undirected graph with a cycle
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({5, 2}); // 🔥 cycle edge
    DSU du(n);
    bool flag = false;
    
    for(auto j : edges){
        int u = j[0];
        int v = j[1];
        if(du.Find(u) == du.Find(v)){
            flag = true;
            break;
        }
        else{
            du.Union(u,v);
        }
    }
    if(flag){
        cout << "Cycle Detected";
    }
    else{
        cout << "Cycle Not Detected";
    }
    
    return 0;
}