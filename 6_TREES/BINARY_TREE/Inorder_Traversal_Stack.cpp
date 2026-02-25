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

void Inorder_Traversal(Node *root)
{
    stack<Node *> st;
    Node *current = root;
    while (current != NULL ||  !st.empty())
    {
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop(); 

        cout << current->data << " ";
        current = current->right;
    }
}

int main()
{
    Node *root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(50);

    root->left->left = new Node(100);
    root->left->right = new Node(150);

    root->right->left = new Node(200);
    root->right->right = new Node(250);

    cout << "This is the Inorder_Traversal Traversal in Tree : ";
    Inorder_Traversal(root);
}