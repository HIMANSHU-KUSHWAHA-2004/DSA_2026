#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool is_leaf(Node* node){
    if(node->left == nullptr && node->right == nullptr)
        return true;
    return false;
}

void add_left_node(Node* root,vector<int> &answer){
    Node* current = root->left;
    while(current){
        if(!is_leaf(current))
            answer.push_back(current->data);
        if(current->left)
            current = current->left;
        else
            current = current->right;
        
    }
}

void add_leaf_node(Node* root,vector<int> &answer){
    if(is_leaf(root)){
        answer.push_back(root->data);
        return;
    }
    if(root->left)
        add_leaf_node(root->left,answer);
    if(root->right)
        add_leaf_node(root->right,answer);
}

void add_right_node(Node* root,vector<int> &answer){
    Node* current = root->right;
    stack<int> st;
    while(current){
        if(!is_leaf(current))
            st.push(current->data);
         if(current->right)
            current = current->right;
        else
            current = current->left;
    }
    while(!st.empty()){
        int current = st.top();
        answer.push_back(current);
        st.pop();
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

    cout << "Binary Tree Created Successfully!" << endl;
    vector<int> answer;

    if(!is_leaf(root))
        answer.push_back(root->data);

    add_left_node(root,answer);
    add_leaf_node(root,answer);
    add_right_node(root,answer);

    for(auto i : answer){
        cout << i << " " ;
    }
    return 0;
}
