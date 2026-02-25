#include<bits\stdc++.h>
using namespace std;
void counter(int n){
    if(n <= 0)
        return ;
    
    counter(n-1);
    cout << n << " ";
}
int main(){
    int num = 10;
    counter(num);
}