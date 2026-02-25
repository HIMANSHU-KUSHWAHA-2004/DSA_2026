#include<bits/stdc++.h>
using namespace std;
int main(){
    int row,colm;
    cin>>row>>colm;
    int arr[row][colm]; 

    for(int i=0;i<row;i++){
        for(int j=0;j<colm;j++){
            cin>>arr[i][j];
        }
    }
    int trans[row][colm];
    for(int i=0;i<colm;i++){
        for(int j=0;j<row;j++){
            trans[i][j] = arr[j][i];
        }
        cout<<endl;
    }

    for(int i=0;i<colm;i++){
        for(int j=0;j<row;j++){
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }


}