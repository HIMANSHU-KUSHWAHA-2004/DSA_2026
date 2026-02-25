#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> boka = {5,19,11,5,2,3,7,6};
    for(int i : boka){
        cout << i <<  " ";
    }
    cout << endl;
    make_heap(boka.begin(),boka.end());
    //This function will make the Max Heap from the vector
    for(int i : boka){
        cout << i <<  " ";
    }
}