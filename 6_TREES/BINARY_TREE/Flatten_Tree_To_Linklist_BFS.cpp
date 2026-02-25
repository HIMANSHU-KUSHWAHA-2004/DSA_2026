#include<bits\stdc++.h>
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

Node* prevNode;
void Flatten(Node* root) {
    if (root == nullptr)
        return;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* current = st.top();
        st.pop();
        
        if(current->right)
            st.push(current->right);

        if(current->left)
            st.push(current->left);
        
        if(!st.empty())
            current->right = st.top();
        current->left = nullptr;
    }
}

void print(Node* root){
    while(root){
        cout << root->data << " ";
        root = root->right;
    }
}
int main() {
    /*
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
         / \
        8   9
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    Flatten(root);
    print(root);
 
}
