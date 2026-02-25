#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int info;
        Node* ptr;
    /*  AS YOU CAN SEE THAT WE CREATED A CLASS NAME NODE WHICH CONTAIN TWO THINGS ONE IS THE INFO
        AND THE OTHER IS THE ptr POINTER WHICH WILL POINT TO THE NEXT NODE IN THE LINKED LIST(which
        acutally is just a class which hava same thing info and the ptr of next node)
    */
        Node(int val) 
        {
            info = val;
            ptr = NULL;
        }
};

void PrintLinkedList(Node* head){
// Node* first = head;
while(head != NULL){
    cout << head->info <<" "<< head->ptr << " -> " ;
    head = head->ptr;
    }
    cout << "null" ;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    /*THE STATEMENTS WHICH YOU ARE SEE IS FOR THE CREATION OF THE DATA INSIDE THE NODE BUT UNDER
    THE HEAP MEMORY new IS THE KEYWORD WHICH DYNAMICALLY ALLOT THE MEMORY TO THE NODES*/
    Node* third = new Node(30);
    head->ptr = second;
    second->ptr = third;
    PrintLinkedList(head);
    return 0;
}