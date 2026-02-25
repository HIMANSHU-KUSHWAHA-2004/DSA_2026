#include <bits/stdc++.h>
using namespace std;

/* BST Node */
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<Node*> IS_IP(Node* root, int k) {
        Node* suc = nullptr; // Inorder Successor
        Node* pre = nullptr; // Inorder Predecessor

        Node* current = root;

        // Find Successor (smallest value > k)
        while (current != nullptr) {
            if (current->data > k) {
                suc = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }

        current = root;

        // Find Predecessor (largest value < k)
        while (current != nullptr) {
            if (current->data < k) {
                pre = current;
                current = current->right;
            } else {
                current = current->left;
            }
        }

        return {pre, suc};
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        return IS_IP(root, key);
    }
};

// ----------- Driver code (for testing) -----------
int main() {
    /*
            50
           /  \
         30    70
        / \    / \
      20  40  60  90
    */

    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(90);

    Solution sol;
    int key = 65;

    vector<Node*> ans = sol.findPreSuc(root, key);

    if (ans[0])
        cout << "Predecessor: " << ans[0]->data << endl;
    else
        cout << "Predecessor: NULL" << endl;

    if (ans[1])
        cout << "Successor: " << ans[1]->data << endl;
    else
        cout << "Successor: NULL" << endl;

    return 0;
}
