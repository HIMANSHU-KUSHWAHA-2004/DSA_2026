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

bool Checker(Node* root) {
    if (root == nullptr)
        return true;

    if (root->left == nullptr && root->right == nullptr)
        return true;

    int left_value = 0;
    int right_value = 0;

    if (root->left)
        left_value = root->left->data;
    if (root->right)
        right_value = root->right->data;

    return (root->data == left_value + right_value) &&
           Checker(root->left) &&
           Checker(root->right);
}

int main() {
    /*
            10
           /  \
          8    2
         / \    \
        3   5    2
    */

    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3); 
    root->left->right = new Node(5);
    root->right->right = new Node(2);

    cout << "Binary tree created for Children Sum Property example." << endl;

    bool result = Checker(root);
    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
