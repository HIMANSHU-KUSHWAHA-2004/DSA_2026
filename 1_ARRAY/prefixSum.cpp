#include <bits/stdc++.h>
using namespace std;
/*THE MEANING OF THE PRIFIX SUM IS THE SUM OF THE */
int main(){
    int n = 10;
    int arr[n] = {1,5,3,9,8,7,4,6,11,10};
    for(int i = 0;i<n;i++){  
        if(i == 0)
            continue;
        arr[i] = arr[i] + arr[i-1];
    }
    for(int i = 0;i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
    
}