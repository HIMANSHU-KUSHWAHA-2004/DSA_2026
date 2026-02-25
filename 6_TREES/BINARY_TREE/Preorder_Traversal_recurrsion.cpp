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
void Preorder(Node* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
    
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

    cout << "This is the Preorder Traversal in Tree : " ;
    Preorder(root);
}