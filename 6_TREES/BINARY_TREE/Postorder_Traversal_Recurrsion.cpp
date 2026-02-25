#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
void Postorder(Node* root){
    if(root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
    
}
int main(){
    Node* root = new Node(10);

    // Create children properly
    root->left = new Node(20);
    root->right = new Node(50);

    root->left->left = new Node(100);
    root->left->right = new Node(150);

    root->right->left = new Node(200);
    root->right->right = new Node(250);

    cout << "This is the Postorder Traversal in Tree : " ;
    Postorder(root);
}