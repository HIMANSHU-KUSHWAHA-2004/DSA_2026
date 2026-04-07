#include <bits\stdc++.h>
using namespace std;
class DSU
{
private:
    vector<int> Size;
    vector<int> Parent;

public:
    DSU(int no_of_nodes)
    {
        Size.resize(no_of_nodes + 1, 1);
        Parent.resize(no_of_nodes + 1);
        for (int i = 1; i <= no_of_nodes; i++)
        {
            Parent[i] = i;
        }
    }
    int Find(int node)
    {
        if (node == Parent[node])
        {
            return node;
        }
        return Parent[node] = Find(Parent[node]);
    }
    void Union(int u, int v)
    {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv)
        {
            return;
        }
        if (Size[pu] > Size[pv])
        {
            Parent[pv] = pu;
            Size[pu] += Size[pv];
        }
        else
        {
            Parent[pu] = pv;
            Size[pv] += Size[pu];
        }
    }
};
int countComponents(int n, vector<vector<int>> &edges)
{
    DSU dsu(n);

    for (auto e : edges)
    {
        dsu.Union(e[0], e[1]);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (dsu.Find(i) == i)
            count++;
    }
    return count;
}
int main()
{
    int n = 5;
    vector<vector<int>> edges;

    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({5, 2}); // 🔥 cycle edge
    cout << "Number of the Component : " << countComponents(n, edges);
    return 0;
}