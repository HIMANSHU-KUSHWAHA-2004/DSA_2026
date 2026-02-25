#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *Insert_Node(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = Insert_Node(root->left, val);
    else
        root->right = Insert_Node(root->right, val);
}

Node *Build_tree(vector<int> pola)
{
    Node *root = nullptr;
    for (int i : pola)
    {
        root = Insert_Node(root, i);
    }
    return root;
}

bool Searching(Node *root, int key)
{
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    else if(key < root->data)
        return Searching(root->left, key);
    else
        return Searching(root->right, key);
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    Node *root = Build_tree(nums);
    inorder(root);
    cout << endl;
    cout << "5 is present in the BST " << Searching(root, 5);
    cout << endl;
    cout << "10 is Absent in the BST " << Searching(root, 10);
}