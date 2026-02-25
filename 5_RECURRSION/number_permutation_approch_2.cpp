#include<bits\stdc++.h>
using namespace std;
void permu(vector<int> &nums,vector<vector<int>> &answer,map<int,bool> &mpp,vector<int> &temp){
    if(temp.size() == nums.size()){
        answer.push_back({temp});
        return;
    }
    for(int i = 0;i<nums.size();i++){
        if(!mpp[nums[i]]){
            mpp[nums[i]] = true;
            temp.push_back(nums[i]);
            permu(nums,answer,mpp,temp);
            temp.pop_back();
            mpp[nums[i]] = false;
        }
    }
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> answer;
    map<int,bool> mppp;
    vector<int> temp;
    permu(nums,answer,mppp,temp);
    for(auto i: answer){
        for(auto k : i){
            cout << k << " ";
        }
        cout << endl;
    }
}