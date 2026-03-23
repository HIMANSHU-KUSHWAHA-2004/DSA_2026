#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
    🔥 EXAMPLE DRY RUN

    words = {"wrt", "wrf", "er", "ett", "rftt"}

    GRAPH:
    w → e → r → t → f

    FINAL ANSWER = "wertf"
    */

    // 🔷 TOPO SORT FUNCTION
    string TopoSort(vector<vector<int>>& graph, vector<int>& used) {

        vector<int> indegree(26, 0);

        for (int i = 0; i < 26; i++) {
            for (auto nd : graph[i]) {
                indegree[nd]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (used[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans += char(node + 'a');

            for (auto nd : graph[node]) {
                indegree[nd]--;

                if (indegree[nd] == 0) {
                    q.push(nd);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (used[i]) cnt++;
        }

        if (ans.size() != cnt) return "";

        return ans;
    }

    // 🔷 MAIN LOGIC FUNCTION
    string foreignDictionary(vector<string>& words) {

        vector<vector<int>> graph(26);
        vector<int> used(26, 0);

        // mark used characters
        for (auto word : words) {
            for (auto ch : word) {
                used[ch - 'a'] = 1;
            }
        }

        int n = words.size();

        // build graph
        for (int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int sz = min(s1.size(), s2.size());
            bool flag = false;
            int k = 0;

            while (sz--) {
                if (s1[k] != s2[k]) {

                    graph[s1[k] - 'a'].push_back(s2[k] - 'a');

                    flag = true;
                    break;
                }
                k++;
            }

            // invalid case
            if (!flag && s1.size() > s2.size()) {
                return "";
            }
        }

        return TopoSort(graph, used);
    }
};


// 🔷 MAIN FUNCTION
int main() {

    Solution obj;

    // 🔥 TEST CASE
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};

    string ans = obj.foreignDictionary(words);

    if (ans == "") {
        cout << "Invalid dictionary (cycle or wrong input)" << endl;
    } else {
        cout << "Alien Dictionary Order: " << ans << endl;
    }

    return 0;
}