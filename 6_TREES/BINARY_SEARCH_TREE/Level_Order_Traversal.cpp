#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> Level(Node* root){
    if(root == nullptr)
        return {};
    vector<vector<int>> ans;
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
        int size = qu.size();
        vector<int> temp;
        while(size--){
            Node* Boka = qu.front();
            qu.pop();
            temp.push_back(Boka->data);
            if(Boka->left)
                qu.push(Boka->left);
            if(Boka->right)
                qu.push(Boka->right);
        }
        ans.push_back({temp});
    }
    return ans;
}

int main() {
    /*
            50
           /  \
         30    60
        / \    / \
      5   20  45  70
                  / \
                 65  80
    */

    Node *root = new Node(50);

    root->left = new Node(35);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(55);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    vector<vector<int>> code = Level(root);
    for(auto i : code){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
