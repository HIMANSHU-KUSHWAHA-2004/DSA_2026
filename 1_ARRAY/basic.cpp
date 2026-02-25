#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6};
    cout << "This will show the number*sizeofdatatype : " << sizeof(arr) << endl;
    cout << "This will show the number of element if we divide sizeof(array) to the size of data : " << sizeof(arr)/sizeof(arr[0]) << endl;
    return 0;
}
