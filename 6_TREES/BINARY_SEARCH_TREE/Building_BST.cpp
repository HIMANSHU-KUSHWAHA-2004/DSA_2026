#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Not necessarily balanced (works for unsorted/random insertion)
Node *Insert_Node(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = Insert_Node(root->left, val);
    else
        root->right = Insert_Node(root->right, val);

    return root; // ✅ must return
}

Node *Build_tree(const vector<int> &pola)
{
    Node *root = nullptr;
    for (int x : pola)
        root = Insert_Node(root, x);
    return root;
}

// Balanced BST from sorted array
Node* Binary_search_Maker(vector<int> &nums, int l, int r)
{
    if (l > r) return nullptr;

    int m = l + (r - l) / 2;
    Node* root = new Node(nums[m]);

    root->left  = Binary_search_Maker(nums, l, m - 1);
    root->right = Binary_search_Maker(nums, m + 1, r); 

    return root;
}

void inorder(Node* root)
{
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4, 10, 8, 11};

    Node* root = Build_tree(nums);
    inorder(root);
    cout << endl;

    vector<int> bola = nums;
    sort(bola.begin(), bola.end());

    Node* pola = Binary_search_Maker(bola, 0, (int)bola.size() - 1); // ✅
    inorder(pola);
}
