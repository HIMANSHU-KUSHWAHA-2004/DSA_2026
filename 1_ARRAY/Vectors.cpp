#include <iostream>
#include <vector>
using namespace std;
int main(){
    /* A vector is a dynamic array that can grow or shrink in size. In programming languages like C++ (in the Standard Template Library), std::vector is a commonly used implementation.
    SYNTAX IS vector<datatype> variable name
    OR IF YOU WANT YOU CAN ALSO SET THE SIZE OF THE VECTOR IN THE LIKE vector<datatype> variable name(size)*/
    vector <int> n;
    cout << "SIZE OF VECTOR WHEN NO ELEMENT IS THERE IN IT : " << n.size() << endl;
    cout << "CAPACITY OF VECTOR WHEN NO ELEMENT IS THERE IN IT : " << n.capacity() << endl;
    /*SO BOTO SIZE AND CAPACITY ARE RELATED BY THAT SIZE <= CAPACITY ALWAYS LIKE IF YOU ADD THE ELEMENTS IN THE VECTOR THEN
    SIZE AND CAPACITY BOTH WILL INCREASE BUT CAPACITY INCREASE IN THE POWER OOF 2 AND ALWAYS GREATER THEN SIZE*/




    n.push_back(1);
    n.push_back(2);
    // THIS IS USED TO PUSH THE ELEMENT IN THE VECTOR
    n.push_back(3);
    n.push_back(4); 




    n.resize(10);
    /*THIS IS USED TO RESIZE THE VECTOR MEANS IT WILL INCREASE OF DECREASE THE SIZE OF THE VECTOR AND IF SIZE INCREASE OF 
    DECREASE THEN CAPACITY AUTOMATICALLY INCREASE OF DECREASE ACCORDING TO THE */



    n.insert(n.begin() + 2 , 5);
    n.insert(n.end() + 2, 6);
    /*THIS IS USED TO INSERT THE ELEMENT IN THE VECTOR AND THE v.begin() MEANS IT WILL TELL YOU THE BEGINNING POSITION OF THE 
    VECTOR AND THE +2 MEANS IT WILL INSERT THE ELEMENT AT THE 3RD POSITION (2ND INDEX) AND THE n>end() IS FOR THE POSTION OF LAST
    ELEMENT*/

    cout << "SIZE OF VECTOR AFTER  ELEMENT IS ADDED IN IT : " << n.size() << endl;
    cout << "CAPACITY OF VECTOR AFTER  ELEMENT IS ADDED IN IT : " << n.capacity() << endl;

    /*TO PRINT THE VECTOR ELEMENTS IN BY USING LOOPS THESE ARE THE TWO METHOD TO PRINT ALL THE ELEMENT OF THE ARRAY*/
    for(int i = 0;i<n.size();i++){
        cout << n[i] << " " ;
    }
    cout << endl;


    for(int i : n){
        cout << i << " ";
    }
    cout << endl;
    
    n.pop_back(); // THIS WILL REMOVE THE LAST ELEMENT FORM THE VECTOR
    n.erase(n.begin() + 2); //THIS WILL DELETE THE ELEMENT FROM THE 2ND INDEX
    // n.clear(); // THIS WILL DELETE ALL THE ELEMENT FROM THE VECTOR

    for(int i = 0;i<n.size();i++){
        cout << n[i] << " " ;
    }


}