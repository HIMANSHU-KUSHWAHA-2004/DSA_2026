#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> Parent;
    vector<int> Size;

public:
    DSU(int n) {
        Parent.resize(n + 1);
        Size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            Parent[i] = i;
        }
    }

    int Find_Parent(int node) {
        if (node == Parent[node])
            return node;

        return Parent[node] = Find_Parent(Parent[node]);
    }

    void Union_set(int u, int v) {
        int par_u = Find_Parent(u);
        int par_v = Find_Parent(v);

        if (par_u == par_v) return;

        // ✅ FIX: use size, not parent value
        if (Size[par_u] < Size[par_v]) {
            Parent[par_u] = par_v;
            Size[par_v] += Size[par_u];
        } else {
            Parent[par_v] = par_u;
            Size[par_u] += Size[par_v];
        }
    }
};

int main() {
    DSU dsu(7);

    // unions
    dsu.Union_set(1, 2);
    dsu.Union_set(2, 3);
    dsu.Union_set(4, 5);
    dsu.Union_set(6, 7);
    dsu.Union_set(5, 6);

    // check same set
    if (dsu.Find_Parent(3) == dsu.Find_Parent(7))
        cout << "Same Set\n";
    else
        cout << "Different Set\n";

    // connect both groups
    dsu.Union_set(3, 7);

    if (dsu.Find_Parent(3) == dsu.Find_Parent(7))
        cout << "Now Same Set\n";
    else
        cout << "Still Different\n";

    return 0;
}