#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int val;

    Node(int data)
    {
        val = data;
        left = right = NULL;
    }
};

// APPROCH 1 - O(N^2)
int height(Node *bhola)
{
    if (bhola == nullptr)
        return 0;
    int l = height(bhola->left);
    int r = height(bhola->right);
    return max(l, r) + 1;
}
int Diamter_lognest(Node* root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int self = lh + rh + 1;

    /*HERE WE WILL FIND THE LEFT HEIGTH AND RIGHT HEIGHT OF THE CURRENT NODE THEN FIND THE DIAMETER
    THAT IS IN THE self AFTER THIS WE WILL ALSO CHECK THE LEFT AND RIGHT SUBTREE SINCE IT MAY 
    POSSIBLE THAT THE LONGEST DIAMETER MAY NOT PASS THROUGH THE ROOT NODE AFTER THAT WE WILL FIND
    THE MAXIMUM OF ALL THREE*/
    int leftDia = Diamter_lognest(root->left);
    int rightDia = Diamter_lognest(root->right);

    return max({self, leftDia, rightDia});
}


// APPROCH 2 - O(N)
int diamter = 0;
int Height(Node *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int left_H = Height(root->left, diameter);
    int right_H = Height(root->right, diameter);

    diameter = max(diameter, left_H + right_H + 1);
    /*THIS FUNCTION WILL NOT GIVE THE ANSWER ITSELF BUT WILL STORE THE ANSWER IN THE GLOBAL VARIABLE
    THAT IS IN THE DIAMETER*/
    return max(left_H, right_H) + 1;
}

int main()
{
    Node *root = new Node(1);

    /* Left subtree (very deep & wide) */
    root->left = new Node(2);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);

    root->left->left->left->left = new Node(16);
    root->left->right->right->right = new Node(17);

    /* Right subtree (small) */
    root->right = new Node(3);
  
    

    /*
                           1
                         /   \
                        2     3
                      /   \     
                     4     5     
                   /   \  /  \
                  8     9 10  11
                 /              \
                16               17



    */

    cout << Diamter_lognest(root) << endl;
    Height(root, diamter);
    cout << diamter << endl;
}