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

Node *Tree_builder(vector<int> &lola, int &idx)
{
    idx++;
    if (lola[idx] == -1)
        return NULL;

    Node *root = new Node(lola[idx]);
    root->left = Tree_builder(lola, idx);
    root->right = Tree_builder(lola, idx);

    return root;
}
void Preorder_Traversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right);
}
int main()
{   
    /*WHAT WE ARE ACTUALLY DOING IS WE ARE GIVEN PREORDER AND THEN WE MAKE A TREE USING THAT PREORDER THEN RETURN THE ROOT OF THAT 
    TREE NOW WE GOT THE ROOT SO WE CAN MAKE DO MANY THINGS LIKE CAN DO A PREORDER,INORDER AND POSTORDER FROM THAT ROOT*/
    vector<int> Preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int tot = -1;
    Node *Root = Tree_builder(Preorder, tot);
    Preorder_Traversal(Root);
    
}