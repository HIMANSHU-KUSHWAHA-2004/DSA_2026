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

// Function to check mirror property
bool check_mirror(Node* left_c, Node* right_c) {
    if (left_c == nullptr || right_c == nullptr)
        return left_c == right_c;

    return (left_c->data == right_c->data) &&
           check_mirror(left_c->left, right_c->right) &&
           check_mirror(left_c->right, right_c->left);
}

int main() {
    /*
             1
           /   \
          2     2
         / \   / \
        3   4 4   3
    */

    Node* root = new Node(1);

    // Left subtree
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);

    // Right subtree (identical to left)
    root->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    // If tree is empty
    if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return 0;
    }

    // Check symmetry
    bool isSym = check_mirror(root->left, root->right);

    if (isSym)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
