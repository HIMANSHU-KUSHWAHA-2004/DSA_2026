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

void all_path(Node* root,vector<int> &temp,vector<vector<int>> &answer){
    if(root == nullptr){
        return;
    }
    temp.push_back(root->data);
    if(root->left == nullptr && root->right == nullptr){
        answer.push_back({temp});
    }
    else{
        all_path(root->left,temp,answer);
        all_path(root->right,temp,answer);
    }
    temp.pop_back();
}

int main() {
    /*
    
            3
           /  \
          5    1
         / \   / \
        6  2  0   8
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
    vector<int> temp;
    vector<vector<int>> answer;
    all_path(root,temp,answer);
    for(auto i : answer){
        for(auto k : i){
            cout << k << " ";
        }
        cout << endl;

    }
}