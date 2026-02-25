#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    
        TreeNode(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }

};

int Node_counter(TreeNode *root){
    if(root == nullptr)
        return 0;
    
    int left_nodes = Node_counter(root->left);
    int right_nodes = Node_counter(root->right);
    return left_nodes + right_nodes + 1;
}

int sum_of_nodes(TreeNode *root){
    if(root == nullptr)
        return 0;
    
    int left_nodes = sum_of_nodes(root->left);
    int right_nodes = sum_of_nodes(root->right);

    return left_nodes + right_nodes + root->data;
}
int main(){
    /*
               1
            /     \
           2       3
         /   \    /   \
        4     5  6     7
       / \   /       /   \
      8   9 10      11    12
              \
               13
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);

    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(12);

    root->left->right->left->right = new TreeNode(13);
    cout << Node_counter(root) << endl;
    cout << sum_of_nodes(root) << endl;

}