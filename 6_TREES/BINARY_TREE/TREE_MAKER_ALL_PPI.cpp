#include <bits/stdc++.h>
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

// Tree builder using your two-argument style
Node* Tree_Builder(vector<int> &level, int &lev) {
    if(lev >= level.size() || level[lev] == -1)
        return nullptr;

    Node* root = new Node(level[lev]);
    queue<Node*> qu;
    qu.push(root);
    lev++;  // move to next index in level

    while(!qu.empty() && lev < level.size()) {
        Node* current = qu.front();
        qu.pop();

        // Left child
        if(lev < level.size() && level[lev] != -1){
            Node* lefter = new Node(level[lev]);
            current->left = lefter;
            qu.push(lefter);
        }
        lev++;

        if(lev < level.size() && level[lev] != -1){
            Node* righter = new Node(level[lev]);
            current->right = righter;
            qu.push(righter);
        }
        lev++;
    }

    return root;
}

// Preorder traversal
void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int> level = {1, 3, 4, 5, 2, 7, 6 };
    int lev = 0;
    Node* root = Tree_Builder(level, lev);
    preorder(root); // output: 8 4 2 6 12 10
}
