#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Container {
public:
    int largest;
    int smallest;
    int size;     
    bool isBST;

    Container(int sml, int lar, int sz, bool ok) {
        smallest = sml;
        largest = lar;
        size = sz;
        isBST = ok;
    }
};

Container* final_info(Node* root) {
    if (root == nullptr) {
        return new Container(INT_MAX, INT_MIN, 0, true); 
    }

    Container* left_info  = final_info(root->left);
    Container* right_info = final_info(root->right);

    if (left_info->isBST && right_info->isBST &&
        left_info->largest < root->data &&
        root->data < right_info->smallest) {

        int curr_smallest = min(left_info->smallest, root->data);
        int curr_largest  = max(right_info->largest, root->data);
        int curr_size     = left_info->size + right_info->size + 1;

        return new Container(curr_smallest, curr_largest, curr_size, true);
    }

    return new Container(INT_MIN, INT_MAX,
                         max(left_info->size, right_info->size),
                         false);
}

int Largest_BST(Node* root) {
    return final_info(root)->size;
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

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    cout << Largest_BST(root) << endl;  

    return 0;
}
