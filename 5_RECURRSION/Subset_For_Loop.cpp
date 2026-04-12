#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans){

    ans.push_back(temp);  // store every step

    for(int i = index; i < arr.size(); i++){

        temp.push_back(arr[i]);        // pick
        solve(i + 1, arr, temp, ans); // move forward
        temp.pop_back();               // backtrack
    }
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, arr, temp, ans);

    // print
    for(auto v : ans){
        for(auto x : v) cout << x << " ";
        cout << endl;
    }
}