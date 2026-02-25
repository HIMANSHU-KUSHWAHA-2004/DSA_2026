#include<bits/stdc++.h>
using namespace std;
int SumPriffixSuffixArray(int *arr,int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += arr[i];
    }
    return sum;

}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int total = SumPriffixSuffixArray(arr,n);
    int start = 0;
    bool found = false;
    for(int i = 0;i<n;i++){
        start += arr[i];
        int last = total - start;
        if(start == last)
            found = true;
            break;
    }
    if(found)
        cout << "true";
    else
        cout << "false" << endl;
}