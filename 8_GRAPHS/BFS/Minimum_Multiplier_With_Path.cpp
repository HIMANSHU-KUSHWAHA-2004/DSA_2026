#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {

        vector<int> visited(100000, 0);
        vector<int> parent(100000, -1);
        vector<int> used(100000, -1);

        queue<pair<int,int>> q;
        q.push({start, 0});
        visited[start] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int num = it.first;
            int steps = it.second;

            if(num == end){
                vector<int> path;
                int cur = end;

                while(cur != start){
                    path.push_back(used[cur]);
                    cur = parent[cur];
                }

                reverse(path.begin(), path.end());

                cout << "Multipliers used: ";
                for(auto x : path) cout << x << " ";
                cout << endl;

                return steps;
            }

            for(auto x : arr){
                int next = (num * x) % 100000;

                if(!visited[next]){
                    visited[next] = 1;
                    parent[next] = num;
                    used[next] = x;

                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {3, 4, 65};
    int start = 7;
    int end = 66175;

    int result = obj.minimumMultiplications(arr, start, end);

    cout << "Minimum steps: " << result << endl;

    return 0;
}