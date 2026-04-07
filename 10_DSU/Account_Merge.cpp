#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> Parent, Size;

public:
    DSU(int n) {
        Parent.resize(n);
        Size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            Parent[i] = i;
        }
    }

    int Find(int node) {
        if (node == Parent[node]) return node;
        return Parent[node] = Find(Parent[node]);
    }

    void Union(int u, int v) {
        int par_u = Find(u);
        int par_v = Find(v);

        if (par_u == par_v) return;

        if (Size[par_u] > Size[par_v]) {
            Parent[par_v] = par_u;
            Size[par_u] += Size[par_v];
        } else {
            Parent[par_u] = par_v;
            Size[par_v] += Size[par_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DSU ds(n);

        unordered_map<string, int> mpp;

        // Step 1: Union accounts using emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = i;
                } else {
                    ds.Union(mpp[mail], i);
                }
            }
        }

        // Step 2: Group mails by parent
        vector<vector<string>> mails(n);

        for (auto &it : mpp) {
            string mail = it.first;
            int node = ds.Find(it.second);
            mails[node].push_back(mail);
        }

        // Step 3: Build answer
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mails[i].empty()) continue;

            sort(mails[i].begin(), mails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);  // name

            for (auto &mail : mails[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    vector<vector<string>> result = sol.accountsMerge(accounts);

    // Print result
    for (auto &acc : result) {
        for (auto &s : acc) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}