#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
void preorder(Node* root){
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int Sum_Tree(Node* root){
    if(root == NULL)
        return 0;

    int sum_l = Sum_Tree(root->left);
    int sum_r = Sum_Tree(root->right);
    root->data += sum_l + sum_r;
    return root->data;
}
int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    // ✅ Pre-built tree using only the Node class
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    preorder(root);
    cout << endl;
    cout << "The sum of all the nodes is = " << Sum_Tree(root) << endl;
    return 0;
}
