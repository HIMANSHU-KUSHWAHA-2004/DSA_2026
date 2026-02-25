#include <bits/stdc++.h>
using namespace std;

// Node class for tree nodes
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Tree class
class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void createTree() {
        int val;
        cout << "Enter value for root (-1 for no node): ";
        cin >> val;
        if (val == -1)
            return;

        root = new Node(val);
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            cout << "\n[Currently at node: " << curr->data << "]\n";

            cout << "Enter left child of " << curr->data << " (-1 for no node): ";
            cin >> val;
            if (val != -1) {
                curr->left = new Node(val);
                q.push(curr->left);
            }

            cout << "Enter right child of " << curr->data << " (-1 for no node): ";
            cin >> val;
            if (val != -1) {
                curr->right = new Node(val);
                q.push(curr->right);
            }
        }
    }

    void levelOrder() {
        if (!root) {
            cout << "Tree is empty\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        cout << "\nLevel order traversal: ";
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }

    vector<int> kth_Nodes(Node* root, int level) {
        vector<int> answer;
        if (root == NULL)
            return {};
        queue<pair<Node*, int>> qu;
        qu.push({root, 1});
        while (!qu.empty()) {
            Node* current = qu.front().first;
            int curr = qu.front().second;
            qu.pop();
            if (curr == level) {
                answer.push_back(current->data);
            }

            if (current->left)
                qu.push({current->left, curr + 1});

            if (current->right)
                qu.push({current->right, curr + 1});
        }
        return answer;
    }

    // ✅ Recursive function for kth level
    void kth_rec(Node* root, int k) {
        if (root == NULL)
            return;

        if (k == 1) {
            cout << root->data << " ";
            return;
        }

        kth_rec(root->left, k - 1);
        kth_rec(root->right, k - 1);
    }
};

int main() {
    Tree t;
    t.createTree();
    t.levelOrder();

    int level;
    cout << "\nEnter the level to print: ";
    cin >> level;

    // Iterative approach
    vector<int> nodes = t.kth_Nodes(t.root, level);
    cout << "\nNodes at level " << level << " (Iterative BFS): ";
    for (int val : nodes)
        cout << val << " ";
    cout << endl;

    // Recursive approach
    cout << "Nodes at level " << level << " (Recursive DFS): ";
    t.kth_rec(t.root, level);
    cout << endl;

    return 0;
}
