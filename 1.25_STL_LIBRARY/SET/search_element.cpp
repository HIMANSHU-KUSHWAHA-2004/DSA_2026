#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int z : s) cout << z << " " ;
    int de;
    cout << "Enter the element you wanna find in the set : ";
    cin >> de;
    if(s.find(de) == s.end())
        cout << "Not found" << endl;
    else {  
        cout << "Found at postion : "<< distance(s.begin(),s.find(de)) << endl;

    }


}