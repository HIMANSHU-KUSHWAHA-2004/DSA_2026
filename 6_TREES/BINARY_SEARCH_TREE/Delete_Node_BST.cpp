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

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *Inorder_Successor(Node *root)
{
    if (root->left == nullptr)
        return root;

    Node *curr = root;
    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
Node *Delete_Node(Node *root, int target)
{
    if (root == NULL)
        return NULL;

    if (root->data > target)
        root->left = Delete_Node(root->left, target);
    else if (root->data < target)
        root->right = Delete_Node(root->right, target);
    else
    {
        // this is the case in which the target is equal to the node
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *IS = Inorder_Successor(root->right);
            root->data = IS->data;
            root->right = Delete_Node(root->right,IS->data);
        }
        return root;
    }
}
int main()
{
    Node *root = new Node(50);
    // Level 1
    root->left = new Node(30);
    root->right = new Node(70);

    // Level 2
    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(90);

    // Level 3
    root->left->left->left = new Node(10);
    root->left->left->right = new Node(25);

    root->left->right->left = new Node(35);
    root->left->right->right = new Node(45);

    root->right->left->left = new Node(55);
    root->right->left->right = new Node(65);
    /*
                     50
                  /      \
                30        70
              /   \      /   \
            20     40   60     90
           / \    / \   / \    / \
         10  25  35 45 55 65  80 100
*/

    root->right->right->left = new Node(80);
    root->right->right->right = new Node(100);
    inorder(root);
    cout << endl;
    Delete_Node(root,70);
    inorder(root);
    return 0;
}