#include <bits/stdc++.h>
using namespace std;
int LargestNumberIndex(int arr[],int size){
    int max = INT_MIN,maxElementIndex = 0;

    for(int i = 0;i<size;i++){
        if(arr[i] > max){
            max = arr[i];
            maxElementIndex = i;
        }
    }
    return maxElementIndex ;


}
int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int firstMaxElementIndex = LargestNumberIndex(arr,10);
    arr[firstMaxElementIndex] = 0;
    int secondMaxElement = LargestNumberIndex(arr,10);
    cout << arr[secondMaxElement] << "\n";
}