#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> testcase = {9,16,4,3};

    for(int i = 0; i < testcase.size(); i++){
        int input = testcase[i];
        int height = 0;

        while(input > 1){
            input /= 2;
            height++;
        }

        cout << height << " ";
    }
}