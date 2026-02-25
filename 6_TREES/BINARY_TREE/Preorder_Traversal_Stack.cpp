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

vector<int> Preorder_stack(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *current = st.top();
        st.pop();
        ans.push_back(current->data);

        if (current->right)
            st.push(current->right);
        if (current->left)
            st.push(current->left);
    }
}
int main()
{
    Node *root = new Node(10);
    // Create children properly
    root->left = new Node(20);
    root->right = new Node(50);

    root->left->left = new Node(100);
    root->left->right = new Node(150);

    root->right->left = new Node(200);
    root->right->right = new Node(250);
    vector<int> Pre = Preorder_stack(root);
    cout << "This is the Preorder Traversal in Tree : ";
    for(int i : Pre){
        cout << i << " ";
    }
}