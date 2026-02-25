#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Iterative Postorder using two stacks
    void postorder(Node* node) {
        if (node == nullptr) return;

        stack<Node*> s1, s2;
        
        s1.push(node);

        while (!s1.empty()) {
            Node* cur = s1.top();
            s1.pop();
            s2.push(cur);

            if (cur->left) s1.push(cur->left);
            if (cur->right) s1.push(cur->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->val << " ";
            s2.pop();
        }
    }
};

int main() {
    BinaryTree tree;

    // Build tree
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}
