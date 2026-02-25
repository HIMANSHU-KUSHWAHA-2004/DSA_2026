#include<bits\stdc++.h>
using namespace std;
void sum_maker(int idx,int sum,vector<int> &given,vector<int> &answer){
    if(idx == given.size()){
        answer.push_back(sum);
        return;
    }
    //Here we are including the number in the sum 
    sum_maker(idx + 1,sum + given[idx],given,answer);
    //Here we are not including the number in the sum
    sum_maker(idx + 1,sum,given,answer);
}
int main(){
    vector<int> pola = {1,2,3};
    vector<int> answer;
    sum_maker(0,0,pola,answer);
    for(auto i : answer){
        cout << i << " ";
    }
}